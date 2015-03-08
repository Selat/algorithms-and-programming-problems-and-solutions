#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

/*
 * 11.1.8. The game starts with k groups of n_1, ... , n_k matches; two players take
 * turns removing matches; at each move, a player can remove any number of matches
 * from one group (and may remove the group altogether). The player who cannot make
 * a move (no matches left) loses the game. Who wins if both players do their best?
 * (This game is sometimes called Nim.)
 */

using namespace std;


/*
 * If xor of all values n_1, ... n_k isn't equal to zero, than first player
 * can change number of matches in one of the groups in such way that xor of all updated
 * values would be equal to zero. Later regardless movements of the second player first
 * player is able to maintain the same behaviour unless all groups became empty.
 * If xor of all values n_1, ... n_k is equal to zero, than second player acts as a first
 * player in the preceding strategy.
 */

void print(vector <int> &a)
{
	cout << "Groups: ";
	for(int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int equalize(vector <int> &a)
{
	int s = 0;
	for(int i = 0; i < a.size(); ++i) {
		s ^= a[i];
	}
	int bitid = sizeof(int) * 8 - 1;
	while(!((1 << bitid) & s)) ++bitid;
	int id = 0;
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] & (1 << bitid)) {
			id = i;
			break;
		}
	}
	a[id] -= s;
	cout << "Player 1 takes " << s << " matches from group " << id << endl;
	print(a);
	return s;
}

void runWinStrategy(vector <int> &a)
{
	int id, num;
	int sum = 0;
	for(int i = 0; i < a.size(); ++i) {
		sum += a[i];
	}
	while(sum > 0) {
		cout << "Player 2 step (group id, matches num): ";
		cin >> id >> num;
		a[id] -= num;
		sum -= num;

		sum -= equalize(a);
	}
	cout << "Player 1 wins!" << endl;
}

int getXor(vector <int> &a)
{
	int s = 0;
	for(int i = 0; i < a.size(); ++i) {
		s ^= a[i];
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	int s = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		s ^= a[i];
	}

	if(s != 0) {
		cout << "First player wins" << endl;
		equalize(a);
		runWinStrategy(a);
	} else {
		cout << "Second player wins" << endl;
		bool first_wins = false;
		int id, num;
		int sum = 0;
		for(int i = 0; i < a.size(); ++i) {
			sum += a[i];
		}
		while(sum > 0) {
			s = getXor(a);
			if(s != 0) {
				first_wins = true;
				equalize(a);
				runWinStrategy(a);
				break;
			}

			// Just take the first non-empty group
			for(int i = 0; i < a.size(); ++i) {
				if(a[i] > 0) {
					id = i;
					break;
				}
			}
			cout << "Player 1 takes " << a[id] << " matches from group " << id << endl;
			sum -= a[id];
			a[id] = 0;
			print(a);

			cout << "Player 2 step (group id, matches num): ";
			cin >> id >> num;
			a[id] -= num;
			sum -= num;
		}
		if(!first_wins) {
			cout << "Player 2 wins!" << endl;
		}
	}
	return 0;
}
