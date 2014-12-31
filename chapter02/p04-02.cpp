#include <iostream>
#include <vector>

using namespace std;

/*
 * 2.4.2. In this problem we also represent partitions as non-increasing sequences,
 * but now we want to generate them in reversed alphabetic order (e.g., for n=4, we
 * would generate 4, 3+1, 2+2, 2+1+1, 1+1+1+1).
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
	x[0] = n;
	int k = 0;
	print(x, 1);
	while(k != n - 1) {
		int s = k;
		while(!((s == 0) || (x[s] != 1))) --s;
		--x[s];
		int sum = 1 + k - s;
		for(int i = 1; sum > 0; ++i) {
			if(sum >= x[s]) {
				x[s + i] = x[s];
				sum -= x[s];
			} else {
				x[s + i] = sum;
				sum = 0;
			}
			k = s + i;
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
