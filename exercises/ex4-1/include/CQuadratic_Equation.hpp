#pragma once
struct myComplex {
    double r;
    double im;
};

class CQuadratic_Equation {
public:
    CCoeffs<double> coeffs;
    myComplex sol1;
    myComplex sol2;
    CQuadratic_Equation() {
        sol1.r = 0; sol2.r = 0; sol1.im = 0; sol2.im = 0;
    };
    void solve();
    void print_solution();
    void read();
    void write();
};
void solve();
void print_solution();
void read();
void write();
