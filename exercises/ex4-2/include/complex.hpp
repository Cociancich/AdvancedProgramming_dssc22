#pragma once
#include <iostream>

template <typename T>
class CComplex{
public:
    T x;
    T y;
    CComplex(const T& x0,const T& y0):x(x0),y(y0){};
    template <typename M>
    CComplex operator+(const M& var);
    template <typename M>
    CComplex operator*(const M& var);
    template <typename M>
    CComplex operator-(const M& var);
    //CComplex operator/(const T& var);//lecturer is lazy to type this one
    template <typename M>
    friend std::ostream& operator<<(std::ostream& os, const M& c) {
        if (c.y > 0) {
            os << c.x << " + i*" << c.y;
        }
        else if (c.y < 0) {
            os << c.x << " - i*" << -c.y;
        }
        else {
            os << c.x;
        }
        return os;
    };
    
};
/*
template <typename T>
template <typename M>
std::ostream& operator<<(std::ostream& os, const CComplex& c){
    if(c.y>0){
        os<<c.x<<" + i*"<<c.y;
    }else if (c.y<0){
        os<<c.x<<" - i*"<<-c.y;
    }else{
        os<<c.x;
    }
    return os;
};
*/
template <typename T>
template <typename M>
CComplex<T> CComplex<T>::operator+ ( const M& var ) {
    CComplex result(0,0);
    result.x=x+var.x;
    result.y=y+var.y;
    return result;
}

template <typename T>
template <typename M>
CComplex<T> CComplex<T>::operator- ( const M& var ) {
    CComplex result(0,0);
    result.x=x-var.x;
    result.y=y-var.y;
    return result;
}

template <typename T>
template <typename M>
CComplex<T> CComplex<T>::operator* ( const M& var ) {
    CComplex result(0,0);
    result.x=x*var.x-y*var.y;
    result.y=x*var.y+y*var.x;
    return result;
}




