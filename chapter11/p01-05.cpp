#include <iostream>

/*
 * 11.1.4. Consider a game with similar rules: each player may take 1, 2, or 4
 * matches and loses if there are no matches. Who wins if a game is started with 20
 * matches (and both players play optimally)?
 * 11.1.5. What is the winning strategy for the first player?
 */

using namespace std;

void runWinStrategy(int n)
{
	int num = n % 3;
	cout << "Player 1 takes: " << num << endl;
	n -= num;
	cout << "Number of matches: " << n << endl;
	while(n > 0) {
		cout << "Player 2 takes: ";
		cin >> num;
		n -= num;
		cout << "Number of matches: " << n << endl;
		num = n % 3;
		cout << "Player 1 takes: " << num << endl;
		n -= num;
		cout << "Number of matches: " << n << endl;
	}
	cout << "Player 1 wins!" << endl;
}

int main()
{
	int n;
	cin >> n;
	if(n % 3 != 0) {
		runWinStrategy(n);
	} else {
		int num;
		bool first_won = false;
		while(n > 0) {
			if(n % 3 != 0) {
				runWinStrategy(n);
				first_won = true;
				break;
			}
			num = 1;
			cout << "Player 1 takes: " << num << endl;
			n -= num;
			cout << "Number of matches: " << n << endl;

			cout << "Player 2 takes: ";
			cin >> num;
			n -= num;
			cout << "Number of matches: " << n << endl;
		}
		if(!first_won) {
			cout << "Player 2 wins!" << endl;
		}
	}
	return 0;
}
