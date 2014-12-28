#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.3.2. Write a program that prints all permutations of the numbers 1..n (each
 * should be printed once).
 */

vector <int> a;

void printSequences(int n, int k, int cur = 0)
{
	if(cur == k) {
		for(int i = 0; i < a.size(); ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	} else {
		int i;
		if(cur == 0) {
			i = cur + 1;
		} else {
			i = a[cur - 1] + 1;
		}
		for(; i <= n - (k - cur) + 1; ++i) {
			a[cur] = i;
			printSequences(n, k, cur + 1);
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	a.resize(k);
	for(int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}
	printSequences(n, k);
	return 0;
}
