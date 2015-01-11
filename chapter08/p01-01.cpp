#include <iostream>

using namespace std;

/*
 * 8.1.1. The following recursive procedure computes binomial coefficients. Write
 * an equivalent program without recursion.
 */

long long c[100][100];

long long C(int n, int k)
{
	c[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}

	k = min(k, n - k);
	return c[n][k];
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << C(n, k) << endl;
	return 0;
}
