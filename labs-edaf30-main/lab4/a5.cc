#include "date.h"
#include <iostream>
#include <stdexcept>
#include "string_cast.h"

using std::cout;
using std::endl;


int main(){
    try {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-6-10");

        std::cout << "Integer: " << i << std::endl;
        std::cout << "Double: " << d << std::endl;
        std::cout << "Date: " << date << std::endl;
    }catch(std::invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}