#include <string>
#include <vector>
#ifndef SIEVE_H

class Sieve{
    public:
    Sieve(std::string& list);
    std::vector<int> getPrime();

    private:
    std::string list;
    std::vector<int> number;
};

#endif