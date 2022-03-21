#include <iostream>
#include <complex>

#define INF 100000000
#define NO_ROOTS QuadEqRoots(0, 0, 0)
#define INF_ROOTS QuadEqRoots(0, 0, INF)

using namespace std;
using Complex = complex<double>;

struct QuadEq {
    double a, b, c;
    QuadEq() : a(0), b(0), c(0) {}
    QuadEq(const double a_, const double b_, const double c_) : a(a_), b(b_), c(c_) {}
};

struct QuadEqRoots {
    Complex x1, x2;
    size_t cnt;
    QuadEqRoots(const Complex& x1_, const Complex& x2_, const size_t cnt_) :
        x1(x1_), x2(x2_), cnt(cnt_) {}
};

QuadEqRoots SolveQuadraticEquation(const QuadEq& eq) {
    if (eq.a == 0.0) {
        if (eq.b == 0.0)
            return eq.c == 0.0 ? INF_ROOTS : NO_ROOTS;
        Complex root(-eq.c / eq.b);
        return QuadEqRoots(root, root, 1);
    }
    Complex discriminantSqrt = sqrt(Complex(eq.b * eq.b - 4 * eq.a * eq.c));
    return QuadEqRoots((-eq.b + discriminantSqrt) / (2 * eq.a),
        (-eq.b - discriminantSqrt) / (2 * eq.a), discriminantSqrt == 0.0 ? 1 : 2);
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
    switch (roots.cnt) {
    case 0:
        cout << "Equation has no roots" << endl;
        break;
    case INF: 
        cout << "Every complex is a root" << endl;
        break;
    case 1:
        cout << "The root is " << roots.x1 << endl;
        break;
    case 2:
        cout << "The roots are " << roots.x1 << " and " << roots.x2 << endl;
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