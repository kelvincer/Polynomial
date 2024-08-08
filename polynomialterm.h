#ifndef POLYNOMIALTERM_H
#define POLYNOMIALTERM_H

class PolynomialTerm
{
public:
    PolynomialTerm(float coefficient, unsigned int exponent);
    float getCoefficient() const;
    unsigned int getExponent() const;
    void setCoefficient(float);
    void setExponent(unsigned int);

private:
    float coefficient;
    unsigned int exponent;
};

#endif // POLYNOMIALTERM_H
