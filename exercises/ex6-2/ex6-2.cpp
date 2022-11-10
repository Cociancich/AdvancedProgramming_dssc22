#include <iostream>
#include <cmath>

//examples of dynamic polymoprhism
 
class Shape {
  public:     
      virtual double perimeter() = 0;
	  virtual void print()  = 0;
  // virtual int area ()=0;//makes the class abstract, then you can't have an object of it
    //pure virtual functions must be overriden, otherwise the child class is also abstract
};

class Polygon : public Shape {
public:
	double* vx;
	double* vy;
	int nv;
	double perimeter() override {
		double p = 0;
		for (int i = 0; i < nv; i++) {
			if (i < 2) {
				p = p + (sqrt((vx[i] - vx[i + 1]) * (vx[i] - vx[i + 1]) + (vy[i] - vy[i + 1]) * (vy[i] - vy[i + 1])));
			}
			else {
				p = p + (sqrt((vx[i] - vx[0]) * (vx[i] - vx[0]) + (vy[i] - vy[0]) * (vy[i] - vy[0])));
			}
		}

		return p;
	};
	void print() override {
		std::cout << "Polygon vertices: " << std::endl;
		for (int i = 0; i < nv; i++) {
			std::cout << "(" << vx[i] << ","<<vy[i] << ")" << std::endl;
		}
	}
	Polygon(const int& N) {
		vx = new double[N];
		vy = new double[N];
		nv = N;
		for (int i = 0; i < N; i++) {
			vx[i] = i;
			vy[i] = i + 1;
		}
	};
	~Polygon() { 
		delete[] vx; 
		delete[] vy;
	};
};

class Triangle: public Shape {
  public:
	  double* vx;
	  double* vy;
      
	  double perimeter() override {
		  double p = 0;
		  for (int i = 0; i < 3; i++) {
			  if (i < 2) {
				  p = p + (sqrt((vx[i] - vx[i + 1]) * (vx[i] - vx[i + 1]) + (vy[i] - vy[i + 1]) * (vy[i] - vy[i + 1])));
			  }
			  else {
				  p = p + (sqrt((vx[i] - vx[0]) * (vx[i] - vx[0]) + (vy[i] - vy[0]) * (vy[i] - vy[0])));
			  }
		  }

		  return p;
	  };
	  void print() override {
		  std::cout << "Triangle vertices: " << std::endl;
		  for (int i = 0; i < 3; i++) {
			  std::cout << "(" << vx[i] << ","<<vy[i] << ")" << std::endl;
		  }
	  }
	  Triangle() {
		  vx = new double[3];
		  vy = new double[3];
		  for (int i = 0; i < 3; i++) {
			  vx[i] = i;
			  vy[i] = i + 1;
		  }
	  };
	  ~Triangle() {
		  delete[] vx;
		  delete[] vy;
	  };

};

int main () {
	Shape* ppoly1 = new Polygon(7);

  Triangle trgl;

  Shape* ppoly2 = &trgl;

  std::cout << ppoly1->perimeter() << std::endl;
  std::cout << ppoly2->perimeter() << std::endl;
  ppoly1->print();
  ppoly2->print();
  return 0;
}
