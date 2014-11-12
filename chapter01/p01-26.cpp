#include <iostream>

using namespace std;

/*
 * 1.1.26. Assume the command write(i) is allowed for i = 0, 1, 2,. . .,9. Write
 * a program that prints the decimal representation of a given positive integer n.
 */

void printNum(int n)
{
	int base = 1;
	while(10 * base <= n) {
		base *= 10;
	}
	while(base > 0) {
		cout << n / base;
		n %= base;
		base /= 10;
	}
}

int main()
{
	int n;
	cin >> n;
	printNum(n);
	return 0;
}
