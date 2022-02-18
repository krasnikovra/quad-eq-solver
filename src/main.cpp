#include <iostream>
#include <complex>

using namespace std;

pair<complex<double>, complex<double>> SolveQuadraticEquation(const double a, const double b, const double c) {
    if (a == 0.0)
        throw string("Not a quadratic equation.");
    complex<double> discriminantSqrt = sqrt(complex<double>(b * b - 4 * a * c));
    return pair<complex<double>, complex<double>>((-b + discriminantSqrt) / (2 * a), (-b - discriminantSqrt) / (2 * a));
}

ostream& operator<<(ostream& stream, const complex<double> complex) {
    string res = to_string(complex.real());
    if (complex.imag() != 0.0)
        res += (complex.imag() > 0 ? "+" : "-") + to_string(abs(complex.imag())) + string("i");
    return stream << res;
}

int main() {
    double a = 0, b = 0, c = 0;
    cout << "Input a, b, c of quadratic equation ax^2 + bx + c = 0" << endl;
    cin >> a >> b >> c;
    try {
        auto roots = SolveQuadraticEquation(a, b, c);
        if (roots.first == roots.second)
            cout << "Its root is " << roots.first << endl;
        else
            cout << "Its roots are " << roots.first << " and " << roots.second << endl;
        return 0;
    }
    catch (const string& err) {
        cout << "An error occured: " << endl << err << endl;
        return -1;
    }
}