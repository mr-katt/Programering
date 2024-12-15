#include <iostream>
#include "Date.h" // Assuming Date class is defined as before
#include "toString.h"

int main() {
    int num = 42;
    double pi = 3.14159;
    std::string text = "Hello, world!";
    Date date(2024, 12, 5);

    std::cout << "Integer: " << toString(num) << std::endl;
    std::cout << "Double: " << toString(pi) << std::endl;
    std::cout << "String: " << toString(text) << std::endl;
    std::cout << "Date: " << toString(date) << std::endl;

    return 0;
}