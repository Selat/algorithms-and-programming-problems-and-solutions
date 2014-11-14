#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.3. Not using assignment statement for arrays, write a program that is
 * equivalent to the statement x:=y.
 */

void copyArray(const vector <int> &a, vector <int> &b)
{
	b.resize(a.size());
	for(int i = 0; i < a.size(); ++i) {
		b[i] = a[i];
	}
}

int main()
{
	int n;
	vector <int> a, b;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	copyArray(a, b);
	for(int i = 0; i < n; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}
