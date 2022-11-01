#pragma once
#include <iostream>

template <typename T>
T mySum(const T& arg) {
    return arg;
}


template <typename T, typename... Types>
T mySum(const T& arg, const Types&... args) {
    //std::cout << arg << " ";
    return arg + mySum(args...);
}

/*
template <typename T>
void myPrint(const T& arg){
     std::cout<<arg<<" "<<std::endl;
}


template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
*/

