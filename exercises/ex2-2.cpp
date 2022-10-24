#include <iostream>
#include <utility> //need this for std::swap  
#include <cmath>
#include <complex>

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

class CQuadratic_Equation {
public:
    CCoeffs coeffs;
    std::complex<double> x;
    std::complex<double> y;
    void solve();
    void print_solution();
};

void CQuadratic_Equation::print_solution() {
    std::cout << "The roots are: " << x << " " << y << std::endl;
}

void CQuadratic_Equation::solve() {
    double discr = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
    double inv2a = 1 / (2 * coeffs.a);
    if (discr >= 0) {
        //for performance (which doesn't matter now, but can in general)
        //we calculate the complicated math only once        
     
        x = (-coeffs.b + std::sqrt(discr)) * inv2a;
        y = (-coeffs.b - std::sqrt(discr)) * inv2a;
    }
    else {
        double root_of_discr = std::sqrt(-discr);
        x = std::complex<double>(-coeffs.b * inv2a, root_of_discr * inv2a);
        y = std::complex<double>(-coeffs.b * inv2a, -root_of_discr * inv2a);
       
    }
    
}

int main(){
    //it's nice to first tell the user what your program is doing
    std::cout<<"This program solves a quadratic equation "<<std::endl;
    /*CCoeffs coeffs;

    coeffs.ask_for_input();
    coeffs.print();
    coeffs.solve_quadratic_equation(coeffs);
    */
    CQuadratic_Equation eq;
    eq.coeffs.ask_for_input();
    eq.coeffs.print();
    eq.solve();
    eq.print_solution();

    return 0;
}   
