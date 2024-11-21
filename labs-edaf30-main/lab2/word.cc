#include <string>
#include <vector>
#include "word.h"
#include "dictionary.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t){}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int matches = 0;
	auto it1 = this->trigrams.begin();
	auto it2 = t.begin();
	for(auto i  = 0; i < trigrams.size();i++){
		for( auto i = 0; i < t.size(); i++){
			if (it1 == it2) {
				matches++;
			}
		}
		it1++;
	}		
	return matches;
}

	
