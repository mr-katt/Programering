

#include "word.h"
#include <vector>
#include <fstream>
int main(){
    std::string test = "somethingss";
    std::vector<std::string> testing;
    int count = 0;
    while(test.size()-count >= 3){
        testing.push_back(test.substr(count,3));
        count++;
    }    
    std::string test2 = "somethings";
    std::vector<std::string> testing2;
    int count2 = 0;
    while(test2.size()-count2 >= 3){
        testing2.push_back(test2.substr(count2,3));
        count2++;
    }
    Word word = Word(test,testing);
    Word word2 = Word(test2 ,testing2);
    std::ofstream outfile("testingGetMatches.txt");
    outfile << word2.get_matches(testing);
}   