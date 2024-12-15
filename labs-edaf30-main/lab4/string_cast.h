#ifndef STRING_CAST_H
#define STRING_CAST_H

#include <sstream>
#include <stdexcept>
#include <string>

template <typename T>
T string_cast(const std::string& str) {
    std::istringstream iss(str);
    T result;   
    if (!(iss >> result) || !(iss.eof())){
        throw std::invalid_argument("Invalid argument " + str);
    }
    return result;
}

#endif // TOSTRING_H