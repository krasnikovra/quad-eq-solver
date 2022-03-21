#include <iostream>
#include <complex>

using namespace std;

using QuadEqRoots = pair<complex<double>, complex<double>>;

struct QuadEq {
    double a, b, c;
};

QuadEqRoots SolveQuadraticEquation(const QuadEq& eq, bool* isOk) {
    if (eq.a == 0.0) {
        *isOk = false;
        return QuadEqRoots(0, 0);
    }
    complex<double> discriminantSqrt = sqrt(complex<double>(eq.b * eq.b - 4 * eq.a * eq.c));
    *isOk = true;
    return QuadEqRoots((-eq.b + discriminantSqrt) / (2 * eq.a), (-eq.b - discriminantSqrt) / (2 * eq.a));
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
    if (roots.first == roots.second)
        cout << "The root is " << roots.first << endl;
    else
        cout << "The roots are " << roots.first << " and " << roots.second << endl;
}

bool PrintQuadEqSolution(const QuadEq& eq) {
    bool isOk = false;
    QuadEqRoots roots = SolveQuadraticEquation(eq, &isOk);
    if (isOk)
        PrintQuadEqRootsFancy(roots);
    else
        cout << "Not a quadratic equation" << endl;
    return isOk;
}

int main() {
    // we are getting some quad eq from user
    QuadEq eq = ReadEqFromCin();
    // and giving user back its roots
    return PrintQuadEqSolution(eq) ? 0 : -1;
}