#include <iostream>

using namespace std;

/*
 * 11.1.2. What if the same game is started with 23 matches?
 */

int main()
{
	int n = 20;
	int sum = 5;
	int num;
	cout << "Player 1 takes: " << 3 << endl;
	while(n > 0) {
		cout << "Player 2 takes: ";
		cin >> num;
		cout << "Number of matches: " << n - num << endl;
		n -= 5;
		cout << "Player 1 takes: " << (5 - num) << endl;
	}
	cout << "First player won!" << endl;
	return 0;
}
