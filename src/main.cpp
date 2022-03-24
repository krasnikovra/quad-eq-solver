#include <iostream>
#include <complex>

using namespace std;
using Complex = complex<double>;

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
    Complex GetX1() const { return _x1; }
    Complex GetX2() const { return _x2; }
    Count GetCount() const { return _count; }
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

QuadEqRoots SolveQuadraticEquation(const QuadEq& eq) {
    if (eq.a == 0.0) {
        if (eq.b == 0.0)
            return eq.c == 0.0 ? QuadEqRoots::InfRoots() : QuadEqRoots::NoRoots();
        return QuadEqRoots(-eq.c / eq.b);
    }
    Complex discriminantSqrt = sqrt(Complex(eq.b * eq.b - 4 * eq.a * eq.c));
    return QuadEqRoots((-eq.b + discriminantSqrt) / (2 * eq.a),
        (-eq.b - discriminantSqrt) / (2 * eq.a));
}

bool operator==(const Complex& a, const Complex& b) {
    return a.real() == b.real() && a.imag() == b.imag();
}

ostream& operator<<(ostream& stream, const complex<double>& complex) {
    string res = to_string(complex.real());
    if (complex.imag() != 0.0)
        res += (complex.imag() > 0 ? "+" : "-") + to_string(abs(complex.imag())) + string("i");
    return stream << res;
}

QuadEq ReadEqFromCin() {
    QuadEq res;
    cout << "Input a, b, c of quadratic equation ax^2 + bx + c = 0" << endl;
    cin >> res.a >> res.b >> res.c;
    return res;
}

void PrintQuadEqRootsFancy(const QuadEqRoots& roots) {
    switch (roots.GetCount()) {
    case QuadEqRoots::Count::NO:
        cout << "Equation has no roots" << endl;
        break;
    case QuadEqRoots::Count::INF:
        cout << "Every complex is a root" << endl;
        break;
    case QuadEqRoots::Count::ONE:
        cout << "The root is " << roots.GetX1() << endl;
        break;
    case QuadEqRoots::Count::TWO:
        cout << "The roots are " << roots.GetX1() << " and " << roots.GetX1() << endl;
        break;
    }
}

void PrintQuadEqSolution(const QuadEq& eq) {
    QuadEqRoots roots = SolveQuadraticEquation(eq);
    PrintQuadEqRootsFancy(roots);
}

int main() {
    // we are getting some quad eq from user
    QuadEq eq = ReadEqFromCin();
    // and giving user back its roots
    PrintQuadEqSolution(eq);
    return 0;
}