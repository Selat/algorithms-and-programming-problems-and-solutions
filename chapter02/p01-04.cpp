#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 2.1.4. Print all sequences of length k of positive integers such that the i-th term
 * does not exceed i for all i.
 */

void _printSubsets(int k, vector <int> &prefix, int id = 1)
{
	for(int i = 1; i <= id; ++i) {
		prefix[id - 1] = i;
		if(id < k) {
			_printSubsets(k, prefix, id + 1);
		}
		if(id == k) {
			for_each(prefix.begin(), prefix.end(), [&](int x){cout << x << " ";});
			cout << endl;
		}
	}
}

void printSubsets(int k)
{
	vector <int> prefix(k);
	_printSubsets(k, prefix);
}

int main()
{
	int k;
	cin >> k;
	printSubsets(k);
	return 0;
}
