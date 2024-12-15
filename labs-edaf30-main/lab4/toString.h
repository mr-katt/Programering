#ifndef TOSTRING_H
#define TOSTRING_H

#include <sstream>
#include <string>

template <typename T>
std::string toString(const T& obj) {
    std::ostringstream oss;
    oss << obj;
    return oss.str();
}

#endif // TOSTRING_H