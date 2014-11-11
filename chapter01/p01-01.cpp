#include <iostream>

using namespace std;

/*
 * 1.1.1. Consider two integer variables a and b. Write a program block that
 * exchanges the values of a and b (i.e., the value of a becomes the value
 * of b and vice versa).
 */

int main()
{
	int a, b, t;
	cin >> a >> b;
	t = a;
	a = b;
	b = t;
	cout << a << " " << b << endl;
	return 0;
}
