#include <iostream>
#include <cmath>
#include "CCoeffs.hpp"

/*
template<typename T>
CCoeffs<T>::CCoeffs ( const T& a1, const T& b1, const T& c1 ) {
    a=a1;
    b=b1;
    c=c1;
}
*/
template<typename T>
void CCoeffs<T>::ask_for_input() {
    std::cout<<"Please enter the ax^2+bx+c=0 equation's coefficients"<<std::endl;
    CCoeffs<double> var;
    std::cin >> var.a >> var.b >> var.c;
    
    if(a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
}
/*
void CCoeffs::print() {
    std::cout<<"The equation has the following coefficients:"<<std::endl;
    std::cout<< a << " " << b<<" "<<c<<std::endl;
}
*/
/*
void CCoeffs::read_and_write() {

    std::ifstream input_file("input_file.txt");
    //better to check if it worked, cause it won't complain
    if(input_file){
    	input_file >> a >>b >>c;
    }else{
        std::cout<<"failed opening the file"<<std::endl;
    }

    std::cout<<a<< " " <<b <<" "<< c<<std::endl;
    input_file.close();
}
*/
template<typename T>
    void CCoeffs<T>::print() {
    std::cout<<"The equation has the following coefficients:"<<std::endl;
    std::cout<< a << " " << b<<" "<<c<<std::endl;
}
