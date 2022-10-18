#include <iostream>
#include <utility> //need this for std::swap  
#include <cmath>

class CCoeffs{
public:
    double a;
    double b;
    double c;
    CCoeffs() {
        a = 0;
        b = 0;
        c = 0;
    }
    void print();
    void ask_for_input();
    void solve_quadratic_equation(CCoeffs coeffs);
};

void CCoeffs::print() {
    std::cout << "The coefficients are:" << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "c=" << c << std::endl;
}
void CCoeffs::ask_for_input() {
    std::cout << "please type a b c coefficients:" << std::endl;
    std::cin >> a >> b >> c;
    if (a == 0) {
        std::cout << "This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }

}
void CCoeffs::solve_quadratic_equation(CCoeffs coeffs) {
    double discr = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
    double root;
    if (discr >= 0) {
        //for performance (which doesn't matter now, but can in general)
        //we calculate the complicated math only once
        double inv2a = 1 / (2 * coeffs.a);
        double root_of_discr = std::sqrt(discr);
        double root1 = (-coeffs.b + root_of_discr) * inv2a;
        double root2 = (-coeffs.b - root_of_discr) * inv2a;

        std::cout << "The roots are: " << root1 << " " << root2 << std::endl;
    }
    else {
        double inv2a = 1 / (2 * coeffs.a);
        double root_of_discr = std::sqrt(-discr);
        std::cout << "The roots are: " << -coeffs.b * inv2a << "+i " << root_of_discr * inv2a << std::endl;
        std::cout << -coeffs.b * inv2a << "-i " << root_of_discr * inv2a << std::endl;
    }

}

int main(){
    //it's nice to first tell the user what your program is doing
    std::cout<<"This program solves a quadratic equation "<<std::endl;
    CCoeffs coeffs;

    coeffs.ask_for_input();
    coeffs.print();
    coeffs.solve_quadratic_equation(coeffs);
  
    return 0;
}   
