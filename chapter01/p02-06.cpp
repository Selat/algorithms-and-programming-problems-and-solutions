#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.6. An array x: array[1..n] of integer is given. Compute the number
 * of different elements among x[1]..x[n]. (The number of operations should be of
 * order n 2 .)
 */

int findDiffNum(const vector <int> &a)
{
	int k = 1;
	//invarint relation: k = diff_num(a[0] ... a[i])
	for(int i = 1; i < a.size(); ++i) {
		bool distinct = true;
		for(int j = 0; j < i; ++j) {
			if(a[j] == a[i]) {
				distinct = false;
				break;
			}
		}
		if(distinct) {
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
