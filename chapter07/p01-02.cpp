#include <iostream>

using namespace std;

/*
 * 7.1.2. The factorial of 0 is defined as 0! = 1 (note that n! = n · (n − 1)! for
 * n = 1). Modify the program accordingly.
 */

long long fact(int n)
{
	if(n > 0) {
		return n * fact(n - 1);
	} else {
		return 1ull;
	}
}

int main()
{
	int n;
	cin >> n;
	cout << fact(n) << endl;
	return 0;
}
