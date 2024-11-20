#include "coding.h"
#include <fstream>
#include <iostream>
#include <string>
using std::ifstream;
using std::ofstream;

int main(int argc, const char** argv){
    std::string filename;
    if (argc > 1) {
        filename = argv[1];
    } else{
        std::cout << "enter filename : ";
        std::cin >> filename;
    }
    ifstream input_file(filename,std::ios::binary);
    ofstream output_file(filename + ".dec",std::ios::binary);

    if(!input_file){
        std::cerr << "Input at file.";
        return 1;
    }
    if(!output_file){
        std::cerr << "input at file so i can output.";
        return 1;
    }
    char ch;
    while (input_file.get(ch)) {
        output_file.put(decode(static_cast<unsigned char>(ch)));
    }
    std::cout << "File encoded successfully to " << filename + ".dec" << std::endl;
    return 0;
}


