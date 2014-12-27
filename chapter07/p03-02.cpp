#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.3.2. Write a program that prints all permutations of the numbers 1..n (each
 * should be printed once).
 */

vector <int> a;

void printSequences(int n, int cur = 0)
{
	if(cur == n) {
		for(int i = 0; i < a.size(); ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	} else {
		for(int i = cur; i < n; ++i) {
			swap(a[cur], a[i]);
			printSequences(n, cur + 1);
			swap(a[cur], a[i]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}
	printSequences(n);
	return 0;
}
