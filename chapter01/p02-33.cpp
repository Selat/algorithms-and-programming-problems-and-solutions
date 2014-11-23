#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.33. (This version of the preceding problem is called the “Dutch flag” prob-
 * lem in E. Dijkstra’s book [5].) The array contains n elements; each element is equal to
 * 0, 1, or 2. Sort the array if the only allowed operation (besides reading its elements)
 * is the exchange of two elements of the array. The number of operations should be
 * proportional to n.
 */

void rearrange(vector <int> &a)
{
	int i = 0, j = 0, n = a.size() - 1;
	while(j <= n) {
		if(a[j] < 1) {
			swap(a[i], a[j]);
			++i;
			++j;
		} else if(a[j] > 1) {
			swap(a[j], a[n]);
			--n;
		} else {
			++j;
		}
	}
}

int main()
{
	int n;
	vector <int> a;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	rearrange(a);

	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
