#include <iostream>

using namespace std;

/*
 * 1.1.2. Solve the preceding problem without an auxiliary variable. (Assume all
 * variables accept arbitrary integer values.)
 */

int main()
{
	int a, b;
	cin >> a >> b;
	a = b - a;
	b = b - a;
	a = a + b;
	cout << a << " " << b << endl;
	return 0;
}
