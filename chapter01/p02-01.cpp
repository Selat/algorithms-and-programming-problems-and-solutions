#include <iostream>

using namespace std;

/*
 * 1.2.1. Fill the array x with zeros. (Write a program fragment whose execution
 * guarantees that all values x[1]..x[n] are zero independent of the initial value of x.)
 */

const int n = 100;
int x[n];

void fillWithZeros(int *x, int n)
{
	for(int i = 0; i < n; ++i) {
		x[i] = 0;
	}
}

int main()
{
	fillWithZeros(x, n);
	return 0;
}
