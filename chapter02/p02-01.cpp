#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 2.2.1. Print all permutations of 1..n (i.e., all sequences of length n that contain
 * all the numbers 1 . . . n).
 */

void nextPermutation(vector <int> &a)
{
	if(a.size() >= 2) {
		int k = (int)a.size() - 2;
		while((k > 0) && (a[k] > a[k + 1])) --k;
		int t = k + 1;
		while((t < a.size() - 1) && (a[t + 1] > a[k])) ++t;
		swap(a[k], a[t]);
		reverse(a.begin() + k + 1, a.begin() + a.size());
	}
}

void printPermutation(const vector <int> &a)
{
	for(int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

bool isLastPermutation(const vector <int> &a)
{
	for(int i = 1; i < a.size(); ++i) {
		if(a[i] > a[i - 1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	vector <int> a;
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		a.push_back(i);
	}
	printPermutation(a);
	nextPermutation(a);
	while(!isLastPermutation(a)) {
		printPermutation(a);
		nextPermutation(a);
	}
	if(n > 1) {
		printPermutation(a);
	}
	return 0;
}
