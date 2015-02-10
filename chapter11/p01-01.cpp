#include <iostream>

using namespace std;

/*
 * 11.1.1. There are 20 matches on the table. Two players make alternating moves;
 * each could take any number of matches between 1 and 4. The player who cannot
 * make a move (as there are no more matches) loses the game. Who wins the game if
 * both players play optimally?
 */

int main()
{
	int n = 20;
	int sum = 5;
	int num;
	while(n > 0) {
		cin >> num;
		n -= 5;
		cout << 5 - num << " " << n << endl;
	}
	cout << "Second player won!" << endl;
	return 0;
}
