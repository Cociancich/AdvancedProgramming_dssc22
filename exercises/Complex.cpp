#include <iostream>

class Complex {
public:
    double real;
    double im;

    Complex(const double& x0, const double& y0) :real(x0), im(y0) {};
    Complex operator+(const Complex& var);
    Complex operator*(const Complex& var);
    Complex operator-(const Complex& var);
    Complex operator/(const Complex& var);//lecturer is lazy to type this one
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.im > 0) {
        os << c.real << " + i*" << c.im;
    }
    else if (c.im < 0) {
        os << c.real << " - i*" << -c.im;
    }
    else {
        os << c.real;
    }
    return os;
};

Complex Complex::operator+ (const Complex& var) {
    Complex result(0, 0);
    result.real = real + var.real;
    result.im = im + var.im;
    return result;
}

Complex Complex::operator- (const Complex& var) {
    Complex result(0, 0);
    result.real = real - var.real;
    result.im = im - var.im;
    return result;
}

Complex Complex::operator* (const Complex& var) {
    Complex result(0, 0);
    result.real = (real * var.real - im * var.im);
    result.im = (real * var.im + im * var.real);
    return result;
}

Complex Complex::operator/ (const Complex& var) {
    Complex result(0, 0);
    double den = (var.real * var.real + var.im * var.im);
    result.real = (real * var.real + im * var.im)/ den;
    result.im = (im * var.real - real * var.im)/ den;
    return result;
}

int main() {

    Complex a(2, 2), b(1, 1);
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;
    return 0;
}

