#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.15. Two arrays a: array[0..k] of integer and b: array[0..l] of
 * integer contain the coefficients of two polynomials of degrees k and l respec-
 * tively. Put into c: array[0..m] of integer the coefficients of their product. (Here
 * k, l, m are nonnegative integers such that m = k + l; the array element indexed by i
 * contains the coefficient of x^i .)
 */

void mulPolynomial(const vector <int> &a, const vector <int> &b, vector <int> &c)
{
	c.assign(a.size() + b.size() - 1, 0);
	for(int i = 0; i < a.size(); ++i) {
		for(int j = 0; j < b.size(); ++j) {
			c[i + j] += a[i] * b[j];
		}
	}
}


int main()
{
	int n, m;
	vector <int> a, b, c;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	b.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	mulPolynomial(a, b, c);

	for(int i = 0; i < c.size(); ++i) {
		cout << c[i] << " ";
	}
	cout << endl;
	
	return 0;
}
