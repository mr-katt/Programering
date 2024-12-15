#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "wordle_solver.h"
using std::string;
using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <word_list_file>" << std::endl;
        return 1;
    }

    std::ifstream word_list_file(argv[1]);
    if (!word_list_file) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::vector<std::string> candidates;
    WordleSolver solver(candidates);
    for(string str : candidates){
        cout << str << endl;
    }

    return 0;
}