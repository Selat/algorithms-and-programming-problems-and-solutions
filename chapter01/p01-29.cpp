#include <iostream>

using namespace std;

/*
 * 1.1.29. The same problem with the additional restriction that the total number of operations
 * should be of order sqrt(n). (The previous solution requires about n operations.)
 */

int solve(int n)
{
	int a = 0, s = 0;
	int max_square = 0;
	while(max_square * max_square < n) {
		++max_square;
	}
	--max_square;
	while(a * a < n) {
		// invariant: max_square is maximal integer such that
		// a * a + max_square * max_square < n
		s += max_square + 1;
		++a;
		while(n - a * a - max_square * max_square <= 0) {
			--max_square;
		}
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
