#include <iostream>

using namespace std;

/*
 * 1.1.20. Write a program that prints the squares of the natural numbers 0, ..., n
 * for a given n > 0.
 */

void printSquares(int n)
{
	for(int i = 0; i <= n; ++i) {
		cout << i * i << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	printSquares(n);
	return 0;
}
