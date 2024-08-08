#include <iostream>
#include <memory>
#include <list>
#include "polynomialterm.h"
#include "polynomial.h"

int main()
{
    auto term_0 = std::make_shared<PolynomialTerm>(4, 0);
    auto term_1 = std::make_shared<PolynomialTerm>(5, 1);
    auto term_2 = std::make_shared<PolynomialTerm>(7, 2);
    auto term_3 = std::make_shared<PolynomialTerm>(1, 3);

    std::list<std::shared_ptr<PolynomialTerm>> terms = {term_0, term_1, term_2, term_3};

    //term_0 = term_1;

    Polynomial polynomial{terms};

    for (auto& term : polynomial.getTerms()) {
        std::cout << "coefficient: " << term->getCoefficient() << " exponent: " << term->getExponent() << std::endl;
    }

    std::list<std::shared_ptr<PolynomialTerm>> t0 = {term_0};

    std::list<std::shared_ptr<PolynomialTerm>> t1 = {std::make_shared<PolynomialTerm>(10, 10)};

    Polynomial p1 = {t0};

    Polynomial p2 = {t1};

    //auto p = polynomial + p1 + p2 + p1;

    std::cout << std::endl;

    auto p = polynomial * p2;

    for (const auto& term : p.getTerms()) {
        std::cout << "coefficient: " << term->getCoefficient() << " exponent: " << term->getExponent() << std::endl;
    }

    std::cout << "World" << std::endl;

    return 0;
}
