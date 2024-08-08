#include "polynomialterm.h"

PolynomialTerm::PolynomialTerm(float coefficient, unsigned int exponent):
    coefficient{ coefficient}, exponent{exponent} {}


float PolynomialTerm::getCoefficient() const {
    return coefficient;
}

unsigned int PolynomialTerm::getExponent() const {
    return exponent;
}

void PolynomialTerm::setCoefficient(float new_coefficient) {
    coefficient = new_coefficient;
}
