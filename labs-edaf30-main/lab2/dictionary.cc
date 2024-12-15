#include "dictionary.h"
#include "edit_distance.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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
		int count = 0;
		while(word.size()-count >= 3){
			trigrams.push_back(line.substr(count,3));
			count++;
		}
		sort(trigrams.begin(),trigrams.end());
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
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
    return suggestions;
}
void Dictionary::add_trigrams_suggestions(std::vector<std::string>& suggetions , const std::string &word) const {
	std::ofstream outfiler("testingfor.txt.test");
	for(auto i = word.size()-1; i < word.size()+2 && i < maxLen; i++){
		for(const auto& w : words[i]){
			vector<string> atempt;
			unsigned int count = 0;
			while (word.size()-count >= 3){
            atempt.push_back((word.substr(count, 3)));
            ++count;
			}
			sort(atempt.begin(),atempt.end());

			outfiler << to_string(count) << " " << to_string(w.get_matches(atempt)) << " "; 
			if(w.get_matches(atempt) > count/2){
				suggetions.push_back(w.get_word());
				
			}
		}
	}
	outfiler.close();
}

void Dictionary::rank_suggestions(std::vector<std::string>& suggetions, const std::string &word) const{
	Edit_distance edit;
	std::sort(suggetions.begin(), suggetions.end(),
              [&edit, &word] (const std::string& a, const std::string& b) {
                  return edit.edit_distance(a, word) < edit.edit_distance(b, word);
              });	
}

void Dictionary::trim_suggestions(std::vector<std::string>& suggetions) const{
	if (suggetions.size() > 5){
		for (auto i = 0; i < suggetions.size()-1; i++) {
			if(suggetions.at(i) == suggetions.at(i+1)){
				suggetions.erase(suggetions.begin() + i);
				i--;
			}
		}
	}
	
	while(suggetions.size() > 5){
		suggetions.pop_back();
	}
}