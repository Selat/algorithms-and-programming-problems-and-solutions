#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
 * 2.3.1. Generate all subsets of the set {1..n} having k elements.
 */

void printSubset(const vector<bool> &x)
{
	for(int i = 0; i < x.size(); ++i) {
		if(x[i]) {
			cout << i + 1 << " ";
		}
	}
	cout << endl;
}

bool nextSubset(vector <bool> &x, int k)
{
	int s = x.size() - 2;
	while((s >= 0) && !(!x[s] && x[s + 1])) --s;
	if(s >= 0) {
		int num = 0;
		for(int i = s; i < x.size(); ++i) {
			if(x[i]) ++num;
		}
		x[s] = true;
		// 0000001111100000 ->
		// 0000010000001111
		for(int i = x.size() - num + 1; i < x.size(); ++i) {
			x[i] = true;
		}
		for(int i = s + 1; i < x.size() - num + 1; ++i) {
			x[i] = false;
		}
		return true;
	} else {
		return false;
	}
}

void printSubsets(int n, int k)
{
	assert(n >= k);
	vector <bool> x(n);
	for(int i = x.size() - k; i < x.size(); ++i) {
		x[i] = true;
	}
	printSubset(x);
	nextSubset(x, k);
	do {
		printSubset(x);
	} while(nextSubset(x, k));
}

int main()
{
	int n, k;
	cin >> n >> k;
	printSubsets(n, k);
	return 0;
}
