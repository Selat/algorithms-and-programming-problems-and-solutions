#include <iostream>

using namespace std;

/*
 * 1.1.30. Nonnegative integers n and k are given, with n > 1. Print k digits of the
 * decimal representation of the number 1/n. (If two decimal representations exist, such
 * as 0.499 . . . = 0.500 . . ., print the latter.) The program should use integer variables
 * only.
 */

void printDigits(int n, int k)
{
	int a = 1;
	cout << "0.";
	// invariant: i digits are already printed
	// just perform ordinary division
	for(int i = 0; i < k; ++i) {
		cout << (10 * a) / n;
		a = (10 * a) % n;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	printDigits(n, k);
	return 0;
}
