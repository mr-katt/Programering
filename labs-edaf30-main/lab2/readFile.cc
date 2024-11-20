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
        string triagrams = "";
        while (line.size()-count >= 3){
            triagrams += line.substr(count, 3)+ " ";
            ++count;
        }
        words.push_back(line + " " + to_string(count) + " "+ triagrams);
    }
    fileName.close();
    sort(words.begin(),words.end());
    for(const auto& w : words){
        outfile << w << endl;
    }
    outfile.close();
    return 0;
}