#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/*
 * 9.1.7. Assume all costs a[i][j] are nonnegative. Find the minimal travel cost
 * 1 → i for all i = 1..n in time O(n 2 ).
 *
 * This is Dijkstra algorithm.
 */

const int MAXN = 100;

int n;
int a[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];

void dijkstra(int id)
{
	for(int i = 0; i < n; ++i) {
		d[i] = a[id][i];
	}
	for(int i = 0; i < n; ++i) {
		used[i] = false;
	}
	d[id] = 0;
	used[id] = true;
	for(int i = 1; i < n; ++i) {
		int min_id = -1;
		for(int j = 0; j < n; ++j) {
			if(!used[j] && ((min_id == -1) || (d[min_id] > d[j]))) {
				min_id = j;
			}
		}
		used[min_id] = true;
		for(int j = 0; j < n; ++j) {
			d[j] = min(d[j], d[min_id] + a[min_id][j]);
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
	dijkstra(id);
	for(int i = 0; i < n; ++i) {
		cout << d[i] << " ";
	}
	cout << endl;
	return 0;
}
