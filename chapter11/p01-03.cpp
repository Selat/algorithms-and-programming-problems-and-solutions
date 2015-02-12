#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * 11.1.3. Let us change the rules of the game: the player who takes the last match
 * loses. Who wins if both players do their best? (The answer depends on N .)
 */

void runWinStrategy(int n)
{
	int num = n % 5 - 1;
	if(num < 0) {
		num += 5;
	}
	cout << "Player 1 takes: " << num << endl;
	cout << "Number of matches: " << n - num << endl;
	n -= num;
	while(true) {
		cout << "Player 2 takes: ";
		cin >> num;
		cout << "Number of matches: " << n - num << endl;
		if(n - num == 0) {
			break;
		}
		n -= 5;
		cout << "Player 1 takes: " << (5 - num) << endl;
		cout << "Number of matches: " << n << endl;
	}
	cout << "First player won!" << endl;
}

int main()
{
	srand(time(NULL));
	int sum = 5;
	int num;
	int n;
	cin >> n;

	if((n - 1) % 5 == 0) {
		// Looks like we are going to lose this game
		bool first_won = false;
		while(n > 0) {
			if((n - 1) % 5 != 0) {
				first_won = true;
				runWinStrategy(n);
				break;
			}

			num = ((rand() % min(n, 4)) + 1);
			cout << num << " " << ((rand() % min(n, 4)) + 1)<< endl;
			cout << "Player 1 takes: " << num << endl;
			n -= num;
			cout << "Number of matches: " << n << endl;
			if(n == 0) {
				break;
			}
			cout << "Player 2 takes: ";
			cin >> num;
			n -= num;
			cout << "Number of matches: " << n << endl;
		}
		if(!first_won) {
			cout << "Second player won!" << endl;
		}
	} else {
		// OK, in that case we win easily!
		runWinStrategy(n);
	}
	return 0;
}
