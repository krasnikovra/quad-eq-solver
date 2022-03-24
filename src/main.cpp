#include <iostream>
#include "Utils.h"

using namespace std;

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
    switch (roots.getCount()) {
    case QuadEqRoots::Count::NO:
        cout << "Equation has no roots" << endl;
        break;
    case QuadEqRoots::Count::INF:
        cout << "Every complex is a root" << endl;
        break;
    case QuadEqRoots::Count::ONE:
        cout << "The root is " << roots.getX1() << endl;
        break;
    case QuadEqRoots::Count::TWO:
        cout << "The roots are " << roots.getX1() << " and " << roots.getX1() << endl;
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