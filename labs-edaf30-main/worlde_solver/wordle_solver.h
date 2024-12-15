#ifndef WORDLE_SOLVER_H
#define WORDLE_SOLVER_H

#include <vector>
#include <string>
#include <map>

using size_type = std::string::size_type;
using letters_and_indices = std::map<size_type, std::string>;

class WordleSolver {
public:
    WordleSolver(const std::vector<std::string>& candidates);

    void read_candidates(std::istream &);
    bool contains_any_of(const std::string& s, const std::string& cs);

    // Thees are just help methods for testing
    std::vector<std::string> getCandidates() const {return candidates;};
private:
    bool contains_at(const std::string& s, char c, size_type pos);
    bool contains_but_not_at(const std::string& s, char c, size_type pos);

    std::vector<std::string> candidates;
};

#endif // WORDLE_SOLVER_H