#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.3.5. Generate all representations of a given positive integer n as the sum of a
 * non-increasing sequence of positive integers.
 */

void generate(vector <int> &a, int n, int id, int limit)
{
	if(n == 0) {
		for(int i = 0; i < id; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	} else {
		for(int i = 1; i <= limit; ++i) {
			a[id] = i;
			generate(a, n - i, id + 1, min(i, n - i));
		}
	}
}

void generate(int n)
{
	vector <int> a;
	a.resize(n);
	generate(a, n, 0, n);
}

int main()
{
	int n;
	cin >> n;
	generate(n);
	return 0;
}
