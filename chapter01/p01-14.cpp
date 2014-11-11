#include <iostream>

using namespace std;

/*
 * 1.1.14. Write down a modified version of Euclid’s algorithm that uses the iden-
 * tities
 * GCD(a,b) = GCD(a mod b, b) for a >= b;
 * GCD(a,b) = GCD(a, b mod a) for b >= a.
 */

int gcd(int a, int b)
{
	while((a %= b) && (b %= a));
	return a|b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	return 0;
}
