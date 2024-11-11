#include "separate_fn.h"
#include <iostream>

int main()
{
    the_function("Called from main()");
    std::cout << "This was a linking error not a compiling error. Problem was with finding separate_fn.h" << "\n";
    exit(0);
}
