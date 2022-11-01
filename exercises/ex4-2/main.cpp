#include "complex.hpp"
#include <iostream>

int main() {

    CComplex<int> a(1, 2);
    CComplex<int> b(3, 4);
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    return 0;
}
