#include "TagRemover.h"
#include <iostream>
#include <fstream>

int main() {
    // Open the input HTML file
    std::ifstream inputFile("test.html");

    // Create a TagRemover instance with the input file stream
    TagRemover tr(inputFile);

    // Process the content (remove tags and replace special characters)
    tr.process();

    // Print the processed content to standard output
    tr.print(std::cout);

    // Close the input file
    inputFile.close();

    return 0;
}