#include <iostream>

using namespace std;

/*
 * 7.1.6. Using the procedure write(x) for x = 0 . . . 9, write a recursive proce-
 * dure that prints the decimal representation of a positive integer n.
 */

void write(int x)
{
	cout << x;
}

void print(int n)
{
	if(n < 10) {
		write(n);
	} else {
		print(n / 10);
		write(n % 10);
	}
}

int main()
{
	int n;
	cin >> n;
	print(n);
	return 0;
}
