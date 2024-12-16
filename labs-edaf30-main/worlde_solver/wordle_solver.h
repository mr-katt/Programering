#ifndef WORDLE_SOLVER_H
#define WORDLE_SOLVER_H

#include <vector>
#include <string>
#include <map>

using size_type = std::string::size_type;
using letters_and_indices = std::map<size_type, std::string>; // position character should not exist

class WordleSolver {
public:
    WordleSolver(const std::vector<std::string>& candidates);

    void read_candidates(std::istream &);
    bool contains_any_of(const std::string& s, const std::string& cs);
    bool contains_at(const std::string& s, char c, size_type pos);
    bool contains_but_not_at(const std::string& s, char c, size_type pos);
    void do_filter(std::vector<std::string>& c, const std::string& wrong, const letters_and_indices& green, const letters_and_indices& yellow);
    
    // Functor for grey letters
    struct wrong_fn {
        wrong_fn(const std::string& letters) : letter{letters} {}
        bool operator()(const std::string& c) const;
    private:
        std::string letter;
    };

    // Functor for green letters
    struct correct_fn {
        correct_fn(const letters_and_indices& idxs) : map{idxs} {}
        bool operator()(const std::string& c) const;
    private:
        letters_and_indices map;
    };

    // Functor for yellow letters
    struct misplaced_fn {
        misplaced_fn(const letters_and_indices& idxs) : map{idxs} {}
        bool operator()(const std::string& c) const;
    private:
        letters_and_indices map;
    };

     struct exclude_word {
        exclude_word(const std::string& wrong, const letters_and_indices& correct, const letters_and_indices& misplaced)
            : wrong(wrong), correct(correct), misplaced(misplaced) {}
        bool operator()(const std::string& w) const;
    private:
        wrong_fn wrong;
        correct_fn correct;
        misplaced_fn misplaced;
    };

    // These are just helper methods for testing
    std::vector<std::string> getCandidates() const { return candidates; }

private:
    std::vector<std::string> candidates;
};

#endif // WORDLE_SOLVER_H