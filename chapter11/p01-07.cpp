#include <iostream>
#include <cstdlib>
#include <ctime>

/*
 * 11.1.7. A rook is placed on the chess board; two players make alternating
 * moves. Each player moves the rook left or down. A player that cannot make a move
 * loses the game (this happen when the rook is in a1 position). Who wins if both
 * players do their best?
 */

using namespace std;


/*
 * If n = m, then second player always returns rook to the diagonal cell.
 * If n != m, then first player moves rook to the diagonal cell
 * and then acts as a second player and finally wins.
 */

void runWinStrategy(int n)
{
	int m = n;
	while(m + n > 0) {
		cout << "Player 2 moves to: ";
		cin >> n >> m;

		cout << "Player 1 moves to: ";
		n = m = min(n, m);
		cout << n << " " << m << endl;
	}
	cout << "Player 1 wins!" << endl;
}

void equalizeMatchesNum(int n, int m)
{
	int tmp = min(n, m);
	cout << "Player 1 moves to: " << tmp << " " << tmp << endl;
}

int main()
{
	int n, m;
	cin >> n >> m;
	if(n != m) {
		equalizeMatchesNum(n, m);
		runWinStrategy(n);
	} else {
		bool first_wins = false;
		int id, num;
		while(n + m > 0) {
			if(n != m) {
				first_wins = true;
				equalizeMatchesNum(n, m);
				runWinStrategy(n);
				break;
			}
			cout << "Player 1 moves to: ";
			if(n > 0) {
				n = rand() % max(n / 2, 1);
			} else {
				m = rand() % max(m / 2, 1);
			}
			cout << n << " " << m << endl;

			cout << "Player 2 moves to: ";
			cin >> n >> m;
		}
		if(!first_wins) {
			cout << "Player 2 wins!" << endl;
		}
	}
	return 0;
}
