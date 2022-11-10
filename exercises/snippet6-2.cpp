#include <iostream>
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class Shape {
public:
	virtual void print() {};
	~Shape() {};
};

class Polygon : public Shape {
public:
	double* v;
	void print() override { 
		std::cout << "hi " <<v[3]<< std::endl; 
	};
	Polygon(const int& N) { 
		v = new double[N]; 
		for (int i = 0; i < N; i++) {
			v[i] = i;
		}
	};
	~Polygon() { delete[] v; };
};



int main() {
	Shape* s = new Polygon(7);
	s->print();
}