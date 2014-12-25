#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.3.1. Write a program that prints all sequences of length n composed of the
 * numbers 1..k. (Each sequence should be printed once, so the program prints k^n
 * sequences.)
 */

vector <int> a;

void printSequences(int n, int k, int cur = 0)
{
	if(cur == n) {
		for(int i = 0; i < a.size(); ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	} else {
		for(int i = 1; i <= k; ++i) {
			a[cur] = i;
			printSequences(n, k, cur + 1);
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	a.resize(n);
	printSequences(n, k);
	return 0;
}
