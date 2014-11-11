#include <iostream>

using namespace std;

/*
 * 1.1.12. Repeat the preceding problem with the additional requirement that the
 * number of steps (i.e., the number of assignments performed during the execution)
 * should be of order n (i.e., not greater than Cn for some constant
 */

typedef unsigned long long ull;

long double sum(int n)
{
	long double ans = 1.0l;
	ull cur_fact = 1;
	for(int i = 1; i <= n; ++i) {
		cur_fact *= i;
		ans += 1.0l / cur_fact;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << sum(n) << endl;
	return 0;
}
