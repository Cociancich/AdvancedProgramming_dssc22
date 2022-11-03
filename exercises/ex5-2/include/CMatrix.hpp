#pragma once
#include <iostream>
#include <memory>
#include <array>
#include <fstream>

template <typename T>
class CMatrix {
public:
    //int size;
    size_t size;
    //T* data;
    std::unique_ptr<T[]> data;
    CMatrix(const int& size); 
    //~CMatrix();
    CMatrix() {};
    CMatrix& operator=(const CMatrix& p); //assignment operator
    CMatrix& operator=(CMatrix&& p);    //move assignment
    CMatrix(const CMatrix& p); //copy constructor
    CMatrix(CMatrix&& p); //move constructor
    void print_to_file(const std::string& file);
    void read_from_file(const std::string& file);
    CMatrix<T> operator*(const CMatrix<T>& B);

};

template<typename T>
CMatrix<T>::CMatrix(const int& s) {
    
    //data = new T[s * s];
    data = std::make_unique<int[]>(s*s);
    size = s ;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; ++j) {
            data[i * s + j] = i;
        }
    }
   // std::cout << "constructor called" << std::endl;
}

template <typename T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& p) {
    std::cout << "assignment operator called" << std::endl;
    //first check for self-assignment
    if (this != &p) {
        //copy non-dynamic variables
        size = p.size;
        data.reset(new T[size * size]);
        for (int i = 0; i < size * size; i++) {
            data[i] = p.data[i];
        }
    }//of cheking for self-assignement
    return *this;
};

template <typename T>
CMatrix<T>& CMatrix<T>::operator=(CMatrix<T>&& p) {
    std::cout << "move assignment operator called" << std::endl;
    //first check for self-assignment
    if (this != &p) {
        //copy non-dynamic variables
        size = p.size;
        p.size = 0;
        data = std::move(p.data);
    }//of checking for self-assignment
    return *this;
};

template<typename T>
CMatrix<T>::CMatrix(const CMatrix<T>& p) {
    std::cout << "copy constructor called" << std::endl;
    //first check for self-assignment
    if (this != &p) {
        //copy non-dynamic variables
        size = p.size;
        //create and copy dynamic variables
        data.reset(new T[size *  size]);
        for (int i = 0; i < size * size; i++) {
            data[i] = p.data[i];
        }

    }//of cheking for self-assignement

}//copy constructor

template<typename T>
CMatrix<T>::CMatrix(CMatrix<T>&& p) {
    std::cout << "move constructor called" << std::endl;
    //first check for self-assignment
    if (this != &p) {
        //copy non-dynamic variables
        size = p.size;
        p.size = 0;
        //create and copy dynamic variables
        data = std::move(p.data);
    }//of checking for self-assignment

}

template <typename T>
void CMatrix<T>::read_from_file(const std::string& file) {
    
    std::ifstream filevar(file);
    if (filevar) {
        filevar >> size;
        
        //data.resize(size * size);
        //data = new T[size * size];
        data = std::make_unique<int[]>(size * size);
        for (int i = 0; i < size; ++i) {
           
            for (int j = 0; j < size; ++j) {
               
                filevar >> data[i * size + j];
            }
        }
        filevar.close();
    }
    else {
        std::cout << "coudn't open the file " << file << std::endl;
    }
};



template <typename T>
void CMatrix<T>::print_to_file(const std::string& file) {
    std::ofstream filevar(file);
    filevar << size << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            filevar << data[i * size + j] << " ";
        }
        filevar << std::endl;
    }
    filevar.close();
};

template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& B) {
    if (size != B.size) {
        std::cout << "The two matrices are not of the same size! The result will be nonsense." << std::endl;
    }
    CMatrix<T> C(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C.data[i * size + j] += data[i * size + k] * B.data[k * size + j];
            }
        }
    }
    return C;
};

