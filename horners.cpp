#include <iostream>
#include <vector>
using namespace std;

// Horner's Rule function
double horner(const vector<double>& coeffs, double x) {
    double result = coeffs[0]; // start with highest degree coefficient
    for (size_t i = 1; i < coeffs.size(); i++) {
        result = result * x + coeffs[i];
    }
    return result;
}

int main() {
    int n;
    cout << "Enter degree of polynomial: ";
    cin >> n;

    vector<double> coeffs(n+1);
    cout << "Enter coefficients (a_n ... a_0): ";
    for (int i = 0; i <= n; i++) cin >> coeffs[i];

    double x;
    cout << "Enter value of x: ";
    cin >> x;

    double result = horner(coeffs, x);
    cout << "Polynomial evaluated at x = " << x << " is: " << result << endl;

    return 0;
}
