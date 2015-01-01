#include <iostream>
#include <vector>

using namespace std;

/*
 * 2.4.3. Partitions are represented as non-decreasing sequences; generate them in
 * alphabetic order. For example, when n = 4, we would generate 1+1+1+1, 1+1+2,
 * 1+3, 2+2, 4.
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
		++x[s];
		--x[s + 1];
		if(x[s + 1] < x[s]) {
			x[s] += x[s + 1];
			--k;
		}
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
