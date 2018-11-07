#include "Polynomial.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>


namespace pic10a
{

//vector with one element of degree zero
polynomial::polynomial(double c)
{
    coeff.push_back(c);
}

//degree is 1 less than size of vector
int polynomial::degree()
{

    return coeff.size() - 1;
}

//loop through each element and increment by 1 if coeff is non zero
int polynomial::nonzeroTerms()
{
    int count = 0;
    for (int i = 0; i < coeff.size(); i++)
    {
        if (coeff[i] != 0)
            count++;
    }
    return count;
}

//sets the coeff of the term x^deg to c
void polynomial::setCoeff(int deg, double c)
{
    assert(deg >= 0);
    if (deg + 1 > coeff.size())
        coeff.resize(deg + 1, 0.0); //resize to store higher degree
    coeff[deg] = c;

    int size = coeff.size() - 1;
    while (coeff[size] == 0 && coeff.size()>1)   //decrease
    {
        coeff.pop_back();
        size--;
    }
}

//returns coeff of term x^deg
double polynomial::getCoeff(int deg)
{
    assert(deg >= 0);
    if (degree() <= deg)
        return coeff[deg];
    else
        return 0;
}

//makes the polynomial negative
double polynomial::operator()(double x)
{
    double answer =0;
    for (int i = 0; i < coeff.size(); i++)
        answer += coeff[i] * pow(x, i);


    return answer;
}

polynomial polynomial::operator+(polynomial p)
{
    int length = 0;
    if (degree() > p.degree()) //length is the max of the degrees
        length = degree(); //own max function
    else
        length = p.degree();
    polynomial p_plus;
    for (int i = 0; i < length; i++)
    {
        p_plus.setCoeff(i, getCoeff(i) + p.getCoeff(i));
    }
    return p_plus;
}

polynomial polynomial::operator-(polynomial p)
{
    int length = 0;
    if (degree() > p.degree()) //length is the max of the degrees
        length = degree(); //own max function
    else
        length = p.degree();
    polynomial p_minus;
    for (int i = 0; i < length; i++)
    {
        p_minus.setCoeff(i, getCoeff(i) - p.getCoeff(i));
    }
    return p_minus;
}

polynomial polynomial::operator-()
{
    polynomial p_neg;
    for (int i = 0; i < degree(); i++)
        p_neg.setCoeff(i, getCoeff(i)*(-1));
    return p_neg;
}

polynomial polynomial::operator*(polynomial p)
{
    polynomial product;
    for (int i = 0; i <= (degree() + p.degree()); i++)
    {
        double sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += getCoeff(i) * p.getCoeff(i - j);
        }
        product.setCoeff(i, sum);

    }
    return product;
}

polynomial& polynomial::operator+=(polynomial p)
{
    int length;
    if (degree() > p.degree())
        //length is the max of the degrees
        length = degree();
    else
        length = p.degree();
    for (int i = 0; i < length; i++)
        setCoeff(i, getCoeff(i) + p.getCoeff(i));
    return *this;
}

polynomial& polynomial::operator-=(polynomial p)
{
    int length;
    if (degree() > p.degree()) //length is the max of the degrees
        length = degree(); //own max function
    else
        length = p.degree();
    for (int i = 0; i < length; i++)
    {
        setCoeff(i, getCoeff(i) - p.getCoeff(i));
    }
    return *this;
}

polynomial& polynomial::operator*=(polynomial p)
{
    polynomial product;
    for (int i = 0; i <= (degree() + p.degree()); i++)
    {
        double sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += p.getCoeff(i)* p.getCoeff(i - j);
        }
        product.setCoeff(i, sum);
    }
    for (int i = 0; i <= (degree() + p.degree()); i++)
    {
        setCoeff(i, product.getCoeff(i));
    }
    return *this;
}

std::ostream& operator<<(std::ostream& s, polynomial p)
{
    if (p.degree() == 0 && p.getCoeff(0) == 0.0)
        return (s << double(0));
    for (int i = p.degree(); i >= 0; i--)
    {
        if (p.getCoeff(i) == 0)
            continue;
        if (i < p.degree() && p.getCoeff(i)>0)
            s << "+";
        if (p.getCoeff(i) != 1.0 || i == 0)
            s << p.getCoeff(i);
        if (i == 1)
        {
            s << "x";
        }
        else if (i > 1)
        {
            s << "x^" << i;
        }
    }
    return s;
}

polynomial operator+(double c, polynomial p)
{
    polynomial new_pol(c);
    return new_pol + p;
}

polynomial operator*(double c, polynomial p)
{
    std::cout << "one \n";
    polynomial new_pol(c);
    std::cout << "2 \n";
    return new_pol * p;
}
}
