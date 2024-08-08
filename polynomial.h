#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <list>
#include <memory>
#include "polynomialterm.h"

class Polynomial : public std::enable_shared_from_this<Polynomial>
{
public:
    Polynomial(std::list<std::shared_ptr<PolynomialTerm>>& );

    Polynomial& operator+(const Polynomial & p1);

    Polynomial& operator*(const Polynomial& p1);

    std::list<std::shared_ptr<PolynomialTerm>> getTerms() const;

private:
    std::list<std::shared_ptr<PolynomialTerm>>& terms;
};

#endif // POLYNOMIAL_H
