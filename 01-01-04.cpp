#include <iostream>

using namespace std;

/*
 * 1.1.4. Solve the preceding problem with the additional requirement that the
 * number of execution steps should be of order log n (i.e., it should not exceed C log n
 * for some constant C).
 */

int pow(int a, int n)
{
	int res = 1;
	while(n > 0) {
		if(n & 1) {
			res *= a;
		}
		a *= a;
		n >>= 1;
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
