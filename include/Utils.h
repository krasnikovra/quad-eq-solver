#pragma once

#include <complex>

using Complex = std::complex<double>;

class QuadEqRoots {
public:
    enum class Count {
        NO,
        ONE,
        TWO,
        INF
    };

    QuadEqRoots(const Complex& x) : _x1(x), _x2(x), _count(Count::ONE) {}
    QuadEqRoots(const Complex& x1, const Complex& x2) : _x1(x1), _x2(x2),
        _count(x1 == x2 ? Count::ONE : Count::TWO) {}
    Complex getX1() const { return _x1; }
    Complex getX2() const { return _x2; }
    Count getCount() const { return _count; }
    static QuadEqRoots NoRoots() { return QuadEqRoots(0, 0, Count::NO); };
    static QuadEqRoots InfRoots() { return QuadEqRoots(0, 0, Count::INF); };
private:
    QuadEqRoots(const Complex& x1, const Complex& x2, const Count& count) :
        _x1(x1), _x2(x2), _count(count) {
    }

    Complex _x1, _x2;
    Count _count;
};

struct QuadEq {
    double a, b, c;
    QuadEq() : a(0), b(0), c(0) {}
    QuadEq(const double a_, const double b_, const double c_) : a(a_), b(b_), c(c_) {}
};