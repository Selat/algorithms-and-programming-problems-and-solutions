#include <iostream>

using namespace std;

/*
 * 7.1.4. Repeat the previous problem with the requirement: the recursion depth
 * (number of recursion levels) should not exceed C * log n, where n is the exponent.
 */

double pow(double a, int n)
{
	if(n == 0) {
		return 1.0;
	} else if(n & 1) {
		return a * pow(a, n - 1);
	} else {
		pow(a * a, n / 2)
	}
}

int main()
{
	double a;
	int n;
	cin >> a >> n;
	cout << pow(a, n) << endl;
	return 0;
}
