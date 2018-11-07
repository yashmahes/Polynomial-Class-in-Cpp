#include "polynomial.h"
#include "polynomial.h"
#include "polynomial.h"
#include "polynomial.h"
#include <iostream>
using std::cout;
using std::endl;

using namespace pic10a; //do it to each one

int main() {
	pic10a::polynomial p1;
	p1.setCoeff(0, 1.2);

	p1.setCoeff(3, 2.2);
	//this setCoeff reduces the degree
		//degree of polynomial is now 3
	cout << p1 << endl;//
	cout << -p1 << endl;
	cout << p1 * 2 << endl; //why does this work?
	cout << 2 * p1 << endl;
	p1 *= 4;
	cout << p1 << endl;
	cout << p1.degree() << endl; //should be 3
	cout << p1.nonzeroTerms() << endl; //should be 2

	pic10a::polynomial p2;
	p2.setCoeff(0, 1);
	p2.setCoeff(1, 1);
	pic10a::polynomial p3;
	p3.setCoeff(0, -1);
	p3.setCoeff(1, 1);
	cout << p2 << endl;
	cout << p3 << endl;

	cout << p2.getCoeff(0) << endl;
	cout << p2.getCoeff(1) << endl;
	cout << p2.getCoeff(2) << endl; //should be zero
	cout << p2.getCoeff(3) << endl; //should be zero
	cout << p2.getCoeff(4) << endl; //should be zero
	cout << p2.getCoeff(5) << endl; //should be zero

	cout << p2 + p3 << endl;
	cout << p2 - p3 << endl;
	cout << p2 - p2 << endl;
	cout << p2 * p3 << endl;

	cout << (p2 + p3).degree() << endl; //should be 1
	cout << (p2 - p3).degree() << endl; //should be 0
	cout << (p2 - p2).degree() << endl; //should be 0


	pic10a::polynomial x;
	x.setCoeff(1, 1);
	pic10a::polynomial p4 = -1 + 2 * x + x*x*x;
	cout << p4 << endl;
	cout << p4(0.0) << endl;


}
