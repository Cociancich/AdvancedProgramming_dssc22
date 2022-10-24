#pragma once

template <typename T>
class CCoeffs {
public:
    T a;
    T b;
    T c;
    CCoeffs ( const T& a1, const T& b1, const T& c1 );
    /*
    CCoeffs() {
        a = 0; b = 0; c = 0;
    };
    */
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

void ask_for_input();
void print();
//void read_and_write();
