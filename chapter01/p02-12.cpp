#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.12. An array a: array[0..n] of integer contains the coefficients of a
 * polynomial of degree n. Compute the value of this polynomial at the point x; that is,
 * a[n]* x^n + · · · + a[1]*x + a[0].
 */

double computePolynomial(const vector <int> &a, double x)
{
	double y = a[a.size() - 1];
	for(int i = (int)a.size() - 2; i >= 0; --i) {
		y = y * x + a[i];
	}
	return y;
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

	cout << computePolynomial(a, x) << endl;
	return 0;
}
