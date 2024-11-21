#include "dictionary.h"
#include <fstream>
#include <iostream>
using namespace std;

Dictionary::Dictionary() {
    ifstream infile("words.txt");
    if (!infile) {
        std::cerr << "Error opening words.txt" << std::endl;
        return;
    }
    string line;
    while (std::getline(infile, line)) {
        string word = line.substr(0, line.find_first_of(" "));
        vector<string> trigrams;
		for(int i = line.find_first_of(" "); i < line.size()-3; i+=4){
			trigrams.push_back(line.substr(i,3));
		}
		if(word.length() <= 25){
        words[word.size()].emplace_back(word, trigrams);
		}
    }
}

bool Dictionary::contains(const std::string& word) const {
		auto its = words[word.size()].begin();
		while(its != words[word.size()].end()){
			if(its->get_word() == word){
				return true;
			}
			its++;
		}
	
	return false;
}

std::vector<std::string> Dictionary::get_suggestions(const std::string& word) const {
    std::vector<std::string> suggestions;
	add_trigrams_suggestions(suggestions, word);
    return suggestions;
}
void Dictionary::add_trigrams_suggestions(std::vector<std::string>& suggetions , const std::string &word) const {
	for(int i = word.size()-1; i <= word.size()+1 && i < maxLen; i++){
		for(const auto& w : words[i]){
			vector<string> atempt;
			int count = 0;
			if(word.size() >=3){
				for(auto i = 0; i < word.size()-3;i++){
					atempt.emplace_back(word.substr(i,3));
					count++;
				}
				if(w.get_matches(atempt) > count/2){
					suggetions.emplace_back(w.get_word());
				}
			}
		}
	}
}