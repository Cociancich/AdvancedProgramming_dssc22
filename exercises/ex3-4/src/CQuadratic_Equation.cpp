 
#include <iostream>
#include <cmath>
#include "CCoeffs.hpp"
#include "CQuadratic_Equation.hpp"
#include <fstream>


void CQuadratic_Equation::solve() {
    double discr = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;
	if (discr >= 0){
        //for performance (which doesn't matter now, but can in general)
        //we calculate the complicated math only once
        double inv2a=1/(2*coeffs.a);
        double root_of_discr = std::sqrt(discr);
        sol1.r = (-coeffs.b + root_of_discr)*inv2a;
        sol2.r = (-coeffs.b - root_of_discr)*inv2a;
        
	} else {
        double inv2a=1/(2*coeffs.a);
        double root_of_discr = std::sqrt(-discr);
        sol1.r=-coeffs.b*inv2a; sol1.im=root_of_discr*inv2a;
        sol2.r=-coeffs.b*inv2a; sol2.im=-root_of_discr*inv2a;
    }
        
}//solve_quadratic_equation

void CQuadratic_Equation::print_solution() {
    //not the best printing format
    std::cout<<"solutions are: "<<sol1.r << " + i*" <<sol1.im<<std::endl;
    std::cout<<sol2.r << " + i*" <<sol2.im<<std::endl;
}

void CQuadratic_Equation::read() {

    std::ifstream filevar("input_file.txt");

    if(filevar){
    	filevar >> coeffs.a >>coeffs.b >>coeffs.c;
    }else{
        std::cout<<"failed opening the file"<<std::endl;
    }

    std::cout<<coeffs.a<< " " <<coeffs.b <<" "<< coeffs.c<<std::endl;
    filevar.close();
}

void CQuadratic_Equation::write() {
	std::cout<<"Soluzioni: "<<coeffs.a<< " " <<coeffs.b <<" "<< coeffs.c<<std::endl;
    std::ofstream filevar("solution_history.txt", std::ios_base::app);
    
    filevar << "("<<coeffs.a << ")x^2+(" << coeffs.b << ")x+(" << coeffs.c << "): " << sol1.r << " + i*" << sol1.im << std::endl;
    filevar.close();
}

