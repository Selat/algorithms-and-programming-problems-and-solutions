#include <iostream>
#include <cstdlib>
#include <ctime>

/*
 * 11.1.6. The game starts with two groups of m and n matches. The players take
 * turns taking any number of matches from one group. (E.g., the player may remove
 * the entire group.) A player that cannot make the move (no matches remain) loses the
 * game. Who wins if both players play optimally?
 */

using namespace std;


/*
 * If n = m, then second player just mirrors moves of the first player and wins.
 * If n != m, then first player equalizes number of matches in both heaps
 * and then acts as a second player (mirrors moves) and finally wins.
 */

void runWinStrategy(int n)
{
	int m = n, num, id;
	while(m + n > 0) {
		cout << "Player 2 takes (id, num): ";
		cin >> id >> num;
		cout << "Matches num: " << n << " " << m << endl;

		cout << "Player 1 takes (id, num): ";
		if(id == 1) {
			cout << 2 << " " << num << endl;
		} else {
			cout << 1 << " " << num << endl;
		}
		n = m -= num;
		cout << "Matches num: " << n << " " << m << endl;
	}
	cout << "Player 1 wins!" << endl;
}

void equalizeMatchesNum(int n, int m)
{
	cout << "Player 1 takes (id, num): ";
	if(n > m) {
		cout << 1 << " " << n - m << endl;
		n = m;
	} else {
		cout << 2 << " " << m - n << endl;
		m = n;
	}
	cout << "Matches num: " << n << " " << m << endl;
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
			cout << "Player 1 takes (id, num): ";
			id = rand() % 2 + 1;
			num = rand() % max(n / 2, 1) + 1;
			if(id == 1) {
				n -= num;
			} else {
				m -= num;
			}
			cout << id << " " << num << endl;
			cout << "Matches num: " << n << " " << m << endl;

			cout << "Player 2 takes (id, num): ";
			cin >> id >> num;
			if(id == 1) {
				n -= num;
			} else {
				m -= num;
			}
			cout << "Matches num: " << n << " " << m << endl;
		}
		if(!first_wins) {
			cout << "Player 2 wins!" << endl;
		}
	}
	return 0;
}
