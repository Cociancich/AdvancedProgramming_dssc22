#include "variadic.hpp"
#include <iostream>

int main() {
    int a = mySum(1, 2, 3, 4, 5);
    std::cout << a <<std::endl;

    return 0;
}