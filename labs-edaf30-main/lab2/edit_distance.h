#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

#include <string>
#include "dictionary.h"

class Edit_distance {
public:
    int distances[Dictionary::maxLen + 1][Dictionary::maxLen + 1];
    int edit_distance(const std::string& p, const std::string& q);
};

#endif // EDIT_DISTANCE_H