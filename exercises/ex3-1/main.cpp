#include "CCoeffs.hpp"
#include "CQuadratic_Equation.hpp"
#include <iostream>

int main() {
    //it's nice to first tell the user what your program is doing
    std::cout << "This program solves a quadratic equation " << std::endl;
    CQuadratic_Equation eq;
    eq.coeffs.ask_for_input();
    eq.coeffs.print();
    eq.solve();
    eq.print_solution();

    return 0;
}