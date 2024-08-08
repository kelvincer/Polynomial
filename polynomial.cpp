#include "polynomial.h"
#include "polynomialterm.h"
#include <list>
#include <memory>
#include <iostream>

Polynomial::Polynomial(std::list<std::shared_ptr<PolynomialTerm>>& terms): terms{terms} {}

Polynomial& Polynomial::operator+(const Polynomial& p1) {

    for (auto& c : p1.terms) {
        auto found_term = std::find_if(terms.begin(), terms.end(), [&c](std::shared_ptr<PolynomialTerm> term){

            if(c->getExponent() == term->getExponent()) {
                return true;
            }

            return false;
        });

        if(found_term == terms.end()) {
            terms.push_back(std::make_shared<PolynomialTerm>(c->getCoefficient(), c->getExponent()));
        } else {
            found_term->reset(new PolynomialTerm(c->getCoefficient() + (*found_term)->getCoefficient(), c->getExponent()));
        }
    }

    return *this;
}

Polynomial& Polynomial::operator*(const Polynomial& p1) {
    std::list<std::shared_ptr<PolynomialTerm>> t_l;
    Polynomial polynomial_result{t_l};

    std::list<std::shared_ptr<PolynomialTerm>> parcial_terms;
    for (const auto& c: p1.getTerms()) {
        for (const auto&  p: terms) {
            parcial_terms.push_back(
                std::make_shared<PolynomialTerm>(c->getCoefficient() * p->getCoefficient(),
                                                 c->getExponent() + p->getExponent()));
        }
    }

    //std::cout << "size: " << parcial_terms.size() << std::endl;

    for (const auto& p: parcial_terms) {
        //std::cout << "p: " << p->getCoefficient() << ":" << p->getExponent() << std::endl;
    }

    std::list<unsigned int> exponents;

    for (const auto& t : parcial_terms) {

        if(std::find(exponents.begin(), exponents.end(), t->getExponent()) != exponents.end()) {
            continue;
        }

        std::list<std::shared_ptr<PolynomialTerm>> filtered_list;
        std::copy_if(parcial_terms.begin(), parcial_terms.end(), std::back_inserter(filtered_list)
                     , [&t](std::shared_ptr<PolynomialTerm> t0){
                         if(t0->getExponent() == t->getExponent()) {
                             return true;
                         }
                         return false;
                     });
        float coeff = 0;
        unsigned exp = (*filtered_list.begin())->getExponent();

        exponents.push_back(exp);

        for (const auto& c : filtered_list) {
            coeff += c->getCoefficient();
        }

        //std::cout << "coeff: " << coeff << " exp: " << exp << std::endl;

        t_l.push_back(std::make_shared<PolynomialTerm>(coeff, exp));
    }

    this->terms= t_l;

    return *this;
}

std::list<std::shared_ptr<PolynomialTerm>> Polynomial::getTerms() const {
    return terms;
}
