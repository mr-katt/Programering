#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>

class Word {
public:
    Word(const std::string& w, const std::vector<std::string>& t);
    std::string get_word() const;
    unsigned int get_matches(const std::vector<std::string>& t) const;
private:
    std::string word;
    std::vector<std::string> trigrams;
};
#endif
