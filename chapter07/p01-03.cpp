#include <iostream>

using namespace std;

/*
 * 7.1.3. Write a recursive program that computes the nonnegative integral power
 * of a real number.
 */

double pow(double a, int n)
{
	if(n > 0) {
		return a * pow(a, n - 1);
	} else {
		return 1.0;
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
