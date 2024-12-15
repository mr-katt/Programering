#include "Sieve.h"
#include <vector>
using std::string;
Sieve::Sieve(std::string& list){
    this->list = list;
}   

std::vector<int> Sieve::getPrime(){
    int pos = 0;
    do{
    pos = list.find('p',pos);
    if(pos != list.npos){
        for(int i = pos*2; i < list.length(); i+= pos){
            list[i] = 'c';
        }
        number.push_back(pos);  
        pos++;
    }
    
    }while(list.find('p', pos) != list.npos);

    return number;
}