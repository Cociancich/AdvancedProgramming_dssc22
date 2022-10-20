 
#include <iostream>
#include <cmath>

class CCoeffs{
public:
    double a;
    double b;
    double c;
    CCoeffs(){
        a=0;b=0;c=0;
    };
    void ask_for_input();
    void print();
};

void CCoeffs::ask_for_input() {
    std::cout<<"Please enter the ax^2+bx+c=0 equation's coefficients"<<std::endl;
    std::cin >> a >> b >> c;
    
    if(a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
}

void CCoeffs::print() {
    std::cout<<"The equation has the following coefficients:"<<std::endl;
    std::cout<< a << " " << b<<" "<<c<<std::endl;
}

