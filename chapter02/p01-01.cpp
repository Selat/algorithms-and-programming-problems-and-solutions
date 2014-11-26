#include <iostream>
#include <vector>

using namespace std;

/*
 * 2.1.1. Print all the sequences of length k composed of the numbers 1..n.
 */

void _printSequences(vector <int> &a, int n, int id)
{
	if(id == a.size()) {
		for(int i = 0; i < a.size(); ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	} else {
		for(int i = 1; i <= n; ++i) {
			a[id] = i;
			_printSequences(a, n, id + 1);
		}
	}
}

void printSequences(int n, int k)
{
	vector <int> a(k);
	_printSequences(a, n, 0);
}

int main()
{
	int n, k;
	cin >> n >> k;
	printSequences(n, k);
	return 0;
}
