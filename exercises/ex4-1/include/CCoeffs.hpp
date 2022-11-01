#pragma once
#include <iostream>
#include <cmath>

template <typename T>
class CCoeffs {
public:
    T a;
    T b;
    T c;
    CCoeffs ( const T& a1, const T& b1, const T& c1 );
    
    CCoeffs() {
        a = 0; b = 0; c = 0;
    };
    
    void ask_for_input();
    void print();
    //void read_and_write();
};

template<typename T>
CCoeffs<T>::CCoeffs ( const T& a1, const T& b1, const T& c1 ) {
    a=a1;
    b=b1;
    c=c1;
}

template<typename T>
void CCoeffs<T>::ask_for_input() {
    std::cout << "Please enter the ax^2+bx+c=0 equation's coefficients" << std::endl;
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
}

template<typename T>
void CCoeffs<T>::print() {
    std::cout << "The equation has the following coefficients:" << std::endl;
    std::cout << a << " " << b << " " << c << std::endl;
}
//void read_and_write();
