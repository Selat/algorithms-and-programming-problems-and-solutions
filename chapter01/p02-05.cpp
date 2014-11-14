#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.5. An array x: array[1..n] of integer is given such that x[1] <=
 * x[2] <= ... <= x[n]. Find the number of different elements among x[1]...x[n].
 */

int findDiffNum(const vector <int> &a)
{
	int k = 1;
	//invarint relation: k = diff_num(a[0] ... a[i])
	for(int i = 1; i < a.size(); ++i) {
		if(a[i] != a[i - 1]) {
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
