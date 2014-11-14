#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.8. The same problem where all elements are integers in 1..k and the num-
 * ber of operations should be of order n + k.
 */

int findMax(const vector <int> &a)
{
	int cur_max = a[0];
	// invariant relation: cur_max = max(a[0] ... a[i])
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] > cur_max) {
			cur_max = a[i];
		}
	}
	return cur_max;
}

int findDiffNum(const vector <int> &a)
{
	vector <int> b(findMax(a) + 1, 0);
	int k = 0;
	for(int i = 0; i < a.size(); ++i) {
		++b[a[i]];
	}
	// b[i] - number of elements equal to i
	for(int i = 0; i < b.size(); ++i) {
		if(b[i] > 0) {
			++k;
		}
	}
	return k;
}

int main()
{
	int n;
	vector <int> a;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << findDiffNum(a) << endl;
	return 0;
}
