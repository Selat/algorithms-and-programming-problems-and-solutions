#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.1.8. Write a recursive program that computes the sum of all elements in an
 * array a: array [1..n] of integer.
 */

int sum(vector <int> &a, int id)
{
	if(id == a.size()) {
		return 0;
	} else {
		return a[id] + sum(a, id + 1);
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
	cout << sum(a, 0) << endl;
}
