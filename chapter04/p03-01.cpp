#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 4.3.1. Find the number of different elements in an integer array. The number
 * of operations should be of order n * log n.
 */

int getDiffNum(const vector <int> &a)
{
	vector <int> b;
	b.assign(a.begin(), a.end());
	sort(b.begin(), b.end());
	int prev = b[0];
	int num = 1;
	for(int i = 1; i < b.size(); ++i) {
		if(b[i] != prev) {
			++num;
		}
		prev = b[i];
	}
	return num;
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
	cout << getDiffNum(a) << endl;
	return 0;
}
