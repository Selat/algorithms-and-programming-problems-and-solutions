#include <iostream>

using namespace std;

/*
 * 1.1.3. Let a be an integer and n be a nonnegative integer. Compute a^n. In other
 * words, we ask for a program that does not change the values of a and n and assigns
 * the value an to another variable (say, b). (The program may use other variables as
 * well.)
 */

int pow(int a, int n)
{
	int res = 1;
	for(int i = 0; i < n; ++i) {
		res *= a;
	}
	return res;
}

int main()
{
	int a, n;
	cin >> a >> n;
	cout << pow(a, n) << endl;
	return 0;
}
