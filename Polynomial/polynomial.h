#ifndef polynomial_h_
#define polynomial_h_
#include <iostream>
#include <vector>
using namespace std;
namespace pic10a {

	class polynomial {
	private:
		std::vector<double> coeff;
	public:
		polynomial(double c = 0.0);
		int degree();
		int nonzeroTerms();
		void setCoeff(int deg, double c);
		double getCoeff(int deg);
		double operator()(double x);
		polynomial operator+(polynomial p);
		polynomial& operator+=(polynomial p);
		polynomial operator-();
		polynomial operator-(polynomial p);
		polynomial& operator-=(polynomial p);
		polynomial operator*(polynomial p);
		polynomial& operator*=(polynomial p);
	};

	polynomial operator+(double c, polynomial p);
	polynomial operator*(double c, polynomial p);

	std::ostream& operator<<(std::ostream& s, polynomial p);


}

#endif
