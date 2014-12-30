#include <iostream>
#include <vector>

using namespace std;

/*
 * 2.4.1. Generate all partitions of a given positive integer n; that is, all the repre-
 * sentations of n as a sum of positive integers. We do not take the order of the sum-
 * mands into account. (Example: For n=4, partitions are 1+1+1+1, 2+1+1, 2+2, 3+1
 * and 4.)
 */

void print(const vector <int> &a, int n)
{
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void generate(int n)
{
	vector <int> x(n);
	for(int i = 0; i < n; ++i) {
		x[i] = 1;
	}
	int k = n - 1;
	print(x, n);
	while(k != 0) {
		int s = k - 1;
		while(!((s == 0) || (x[s - 1] > x[s]))) --s;
		++x[s];
		int sum = 0;
		for(int i = s + 1; i <= k; ++i) {
			sum += x[i];
		}
		for(int i = 1; i < sum; ++i) {
			x[s + i] = 1;
		}
		k = s + sum - 1;
		print(x, k + 1);
	}
}

int main()
{
	int n;
	cin >> n;
	generate(n);
	return 0;
}
