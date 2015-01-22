#include <iostream>
#include <climits>

using namespace std;

/*
 * 9.1.2. Find the minimal travel cost from the first city to all other cities in time
 * O(n 3 ).
 *
 * This is Bellman-Ford algorithm.
 */

const int MAXN = 100;

int n;
int a[MAXN][MAXN];
int d[MAXN];

void findPath(int id)
{
	for(int i = 0; i < n; ++i) {
		d[i] = a[id][i];
	}
	d[id] = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				d[j] = min(d[j], d[k] + a[k][j]);
			}
		}
	}
}

int main()
{
	int id;
	cin >> n >> id;
	--id;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	findPath(id);
	for(int i = 0; i < n; ++i) {
		cout << d[i] << " ";
	}
	cout << endl;
	return 0;
}
