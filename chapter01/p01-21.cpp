#include <iostream>

using namespace std;

/*
 * 1.1.21. Repeat the preceding problem, but only addition and subtraction are al-
 * lowed. The number of steps should be of order n.
 */

void printSquares(int n)
{
	int cur_square = 0;
	for(int i = 0; i <= n; ++i) {
		cout << cur_square << endl;
		cur_square += i + i + 1;
	}
}

int main()
{
	int n;
	cin >> n;
	printSquares(n);
	return 0;
}
