#include "Sieve.h"
#include <iostream>
#include <ostream>
#include <vector>

int main(){
    std::string line(100000,'p');
    line[0] = 'c';
    line[1] = 'c';

    Sieve siv(line);
    std::vector<int> test = siv.getPrime();
    for (int a : test) {
        if(a < 200){
        std::cout << a << " ";
        }else{
            std::cout << test.at(test.size()-1) <<" Total amount of prime numbers: "<< test.size() << std::endl;
            break;
        }
    }
    std::cout << std::endl;

    return 0;
}
