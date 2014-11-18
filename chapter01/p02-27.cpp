#include <iostream>
#include <vector>

using namespace std;

int binSearch(const vector <int> &a, int x)
{
	int l = 0, r = a.size() - 1;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(x < a[m]) {
			r = m - 1;
		} else {
			l = m;
		}
	}
	if(a[l] == x) {
		return l;
	} else {
		return a.size();
	}
}

int main()
{
	int n, x;
	vector <int> a;
	cin >> n >> x;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << ((binSearch(a, x) < a.size()) ? "YES" : "NO") << endl;
	return 0;
}
