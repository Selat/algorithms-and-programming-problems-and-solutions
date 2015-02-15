#include <iostream>
#include <vector>

/*
 * 11.1.9. There are n glasses in a row; each contains a coin. Players take their
 * turns by taking out one or two coins with the following restrictions: if you take two
 * coins, they should be in the neighbor glasses. Player who cannot make the move (no
 * coins left) loses the game. Who wins in this game if both players play optimally?
 */

using namespace std;

void runWinStrategy(int n)
{
	vector <bool> used(n, false);
	int not_used_num = n;
	int a[2];
	int num;
	cout << "Player 1 takes: ";
	if(n % 2 == 0) {
		cout << 2 << " " << n / 2 << " " << n / 2 + 1 << endl;
		used[n / 2 - 1] = true;
		used[n / 2] = true;
		not_used_num -= 2;
	} else {
		cout << 1 << " "<< (n + 1) / 2 << endl;
		used[n / 2] = true;
		--not_used_num;
	}
	while(not_used_num > 0) {
		cout << "Player 2 takes: ";
		cin >> num;
		for(int i = 0; i < num; ++i) {
			cin >> a[i];
			used[a[i] - 1] = true;
			--not_used_num;
		}
		cout << "Player 1 takes: ";
		cout << num << " ";
		for(int i = 0; i < num; ++i) {
			cout << (n - a[i] + 1) << " ";
			used[n - a[i]] = true;
			--not_used_num;
		}
		cout << endl;
	}
	cout << "Player 1 wins!" << endl;
}

int main()
{
	int n;
	cin >> n;
	runWinStrategy(n);
	return 0;
}
