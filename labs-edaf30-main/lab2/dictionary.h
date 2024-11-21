#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "word.h"
#include <string>
#include <vector>

class Dictionary {
public:
static constexpr int maxLen{25};
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	
private:
void add_trigrams_suggestions(std::vector<std::string>& suggetions, const 	std::string &word) const;

std::vector<Word> words[maxLen];
};

#endif
