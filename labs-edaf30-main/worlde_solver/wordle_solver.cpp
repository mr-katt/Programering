#include "wordle_solver.h"
#include <algorithm>
#include <iostream>
#include <string>
using std::string;

WordleSolver::WordleSolver(const std::vector<std::string>& candidates) : candidates(candidates) {}

void WordleSolver::read_candidates(std::istream &is) {
    std::string word;
    while (is >> word) {
        if (word.length() == 5) {
            candidates.push_back(word);
        }
    }
}

bool WordleSolver::contains_at(const std::string& s, char c, std::string::size_type pos) {
    return s[pos] == c;
}

bool WordleSolver::contains_but_not_at(const std::string& s, char c, std::string::size_type pos) {
    return s.find(c) != std::string::npos && s[pos] != c;
}

bool WordleSolver::contains_any_of(const std::string& s, const std::string& cs) {
    return std::any_of(cs.begin(), cs.end(), [&s] (char c){
        return s.find(c) != std::string::npos;
    });
}

// Implementation of wrong_fn functor
bool WordleSolver::wrong_fn::operator()(const std::string& word) const {
    for (char ch : letter) {
        if (word.find(ch) != std::string::npos) {
            return true;
        }
    }
    return false;
}

// Implementation of correct_fn functor
bool WordleSolver::correct_fn::operator()(const std::string& word) const {
    for (const auto& pos : map) {
        if (pos.second.size() != 1) {
            std::cout << "Error" << std::endl;
        }
        if (pos.second.at(0) != word.at(pos.first)) {
            return false;
        }
    }
    return true;
}

// Implementation of misplaced_fn functor
bool WordleSolver::misplaced_fn::operator()(const std::string& word) const {
    for (const auto& pos : map) {
        for (char posCh : word) {
            auto index = word.find(posCh);
            if (pos.first == index && posCh == pos.second.at(0) && index != std::string::npos) {
                return false;
            }
        }
    }
    return true;
}

bool WordleSolver::exclude_word::operator()(const std::string& word) const {
    if (wrong(word)) {
        return true;
    }
    if (!correct(word)) {
        return true;
    }
    if (!misplaced(word)) {
        return true;
    }
    return false;
}

void WordleSolver::do_filter(std::vector<std::string>& c, const std::string& wrong, const letters_and_indices& green, const letters_and_indices& yellow) {
    exclude_word excluder(wrong, green, yellow);
    c.erase(std::remove_if(c.begin(), c.end(), [&excluder](string word) {
        return excluder(word);
    }), c.end());
}