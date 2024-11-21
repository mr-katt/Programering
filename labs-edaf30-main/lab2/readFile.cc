#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ifstream fileName("/usr/share/dict/words");
    string line;
    ofstream outfile("words.txt");
    vector<string> words;
    while(getline(fileName,line)){
        for(char& c : line){
            c = tolower(c);
        }
        
        int count = 0;
        vector<string> triagrams = {};
        while (line.size()-count >= 3){
            triagrams.push_back((line.substr(count, 3)));
            ++count;
        }
        sort(triagrams.begin(),triagrams.end());
        string sortedTriagrams;
        for(string w : triagrams){
            sortedTriagrams += w + " ";

        }
        words.push_back(line + " " + to_string(count) + " " + sortedTriagrams);
    }
    fileName.close();
    sort(words.begin(),words.end());
    for(const auto& w : words){
        outfile << w << endl;
    }
    outfile.close();
    return 0;
}