#include "wordle_solver.h"
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

bool WordleSolver::contains_at(const std::string& s, char c, size_type pos) {
    return s.at(pos) == c;
}

bool WordleSolver::contains_but_not_at(const std::string& s, char c, size_type pos) {
    return s.find(c) < s.size();
}

bool WordleSolver::contains_any_of(const std::string& s, const std::string& cs) {
    for (size_type pos = 0; pos < s.length(); pos++) {
        if (contains_at(s, cs[pos], pos)) {
            return true;
        } else if (contains_but_not_at(s, cs[pos], pos)) {
            return true;
        }
    }
    return false;
}

// Implementation of wrong_fn functor
bool WordleSolver::wrong_fn::operator()(const std::string& c) const {
   
}

// Implementation of correct_fn functor (empty)
bool WordleSolver::correct_fn::operator()(const std::string& c) const {
    // Implementation goes here
    return false;
}

// Implementation of misplaced_fn functor (empty)
bool WordleSolver::misplaced_fn::operator()(const std::string& c) const {
    // Implementation goes here
    return false;
}


