#include <iostream>
#include <vector>

using namespace std;

/*
 * 2.4.4. Partitions are represented as non-decreasing sequences. Generate them in
 * reversed alphabetic order. (For n = 4 we have 4, 2+2, 1+3, 1+1+2, 1+1+1+1.)
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
		int sum = 0;
		while((s > 0) && (x[s - 1] >= x[s])) {
			sum += x[s];
			--s;
		}
		if(s == k) {
			if((s == 0) || (x[s - 1] <= (x[s] / 2))) {
				int tmp = x[s];
				x[s] = tmp / 2;
				x[s + 1] = (tmp + 1) / 2;
			} else {
				sum += x[s];
				--s;
				while((s > 0) && (x[s - 1] == x[s])) {
					sum += x[s];
					--s;
				}
				--x[s];
				x[s + 1] = sum + 1;
			}
		} else {
			--x[s];
			x[s + 1] = sum + 1;
		}
		k = s + 1;
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
