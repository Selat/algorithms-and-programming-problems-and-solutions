#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.13. (Requires some calculus; communicated by A.G. Kushnirenko) Extend
 * Horner’s rule to compute not only the value of a polynomial at some point, but also
 * the value of the derivative of the same polynomial at the same point.
 */

double computePolynomialDerivative(const vector <int> &a, double x)
{
	double y = a[a.size() - 1];
	double dy = 0.0;
	// After addition of new coefficient:
	// Q(x) = P(x) * x + c
	// Q'(x) = (P(x) * x)' = P'(x) * x + P(x)
	for(int i = (int)a.size() - 2; i >= 0; --i) {
		dy = dy * x + y;
		y = y * x + a[i];
	}
	return dy;
}


int main()
{
	int n;
	double x;
	vector <int> a;
	cin >> n >> x;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << computePolynomialDerivative(a, x) << endl;
	return 0;
}
