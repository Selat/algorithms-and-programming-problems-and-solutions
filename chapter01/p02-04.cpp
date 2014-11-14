#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.4. Find the maximum value among x[1]..x[n].
 */

int findMax(const vector <int> &a)
{
	int cur_max = a[0];
	// invariant relation: cur_max = max(a[0] ... a[i])
	for(int i = 1; i < a.size(); ++i) {
		if(a[i] > cur_max) {
			cur_max = a[i];
		}
	}
	return cur_max;
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

	cout << findMax(a) << endl;
	return 0;
}
