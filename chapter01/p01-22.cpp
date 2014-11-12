#include <iostream>

using namespace std;

/*
 * 1.1.22. Write a program that prints the factorization of a given integer n > 0.
 * (In other words, it should print prime numbers whose product is equal to n; if n = 1,
 * nothing should be printed.)
 */

void factorize(int n)
{
	// invariant: the product of k and all printed numbers is equal to n.
	int k = n;
	int i = 2;
	while(k != 1) {
		while(k % i != 0) ++i;
		k /= i;
		cout << i << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	factorize(n);
	return 0;
}
