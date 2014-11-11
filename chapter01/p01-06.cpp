#include <iostream>

using namespace std;

/*
 * 1.1.6. Two nonnegative integers a and b are given. Compute a + b. Only assign-
 * ments of the form
 * var1 = var2
 * var = number
 * var1 = var2 + 1
 * are allowed
 */

int sum(int a, int b)
{
	int c = a;
	for(int i = 0; i < b; ++i, ++c);
	return c;
}

int main()
{
	int a, b, t;
	cin >> a >> b;
	cout << sum(a, b) << endl;
	return 0;
}
