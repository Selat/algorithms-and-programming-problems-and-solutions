#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
 * 2.3.2. Generate (in lexicographic order) all increasing sequences of length k
 * consisting of the numbers 1..n. (Example: for n=5, k=2 we get {12 13 14 15 23
 * 24 25 34 35 45}.)
 */

void printSubset(const vector<int> &x)
{
	for(int i = 0; i < x.size(); ++i) {
		cout << x[i] << " ";
	}
	cout << endl;
}

bool nextSubset(vector <int> &x, int n)
{
	int s = x.size() - 1;
	while((s >= 0) && (x[s] >= n - x.size() + s + 1)) --s;
	if(s >= 0) {
		++x[s];
		for(int i = s + 1; i < x.size(); ++i) {
			x[i] = x[i - 1] + 1;
		}
		return true;
	} else {
		return false;
	}
}

void printSubsets(int n, int k)
{
	assert(n >= k);
	vector <int> x(k);
	for(int i = 0; i < k; ++i) {
		x[i] = i + 1;
	}
	printSubset(x);
	nextSubset(x, n);
	do {
		printSubset(x);
	} while(nextSubset(x, n));
}

int main()
{
	int n, k;
	cin >> n >> k;
	printSubsets(n, k);
	return 0;
}
