#include "CMatrix.hpp"
#include <iostream>

int main() {
	CMatrix<double> A, B;
	A.read_from_file("A.txt");
	B.read_from_file("B.txt");
	auto C = A * B;
	C.print_to_file("C.txt");
}