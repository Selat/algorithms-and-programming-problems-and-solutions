#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.7. The same problem with an additional requirement: the number of opera-
 * tions should be of order n log n.
 */

void quickSort(vector <int> &a, int l, int r)
{
	int pivot = a[(l + r) / 2];
	int i = l, j = r;
	while(i <= j) {
		while(a[i] < pivot) ++i;
		while(pivot < a[j]) --j;
		if(i <= j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			++i;
			--j;
		}
	}
	if(l < j) quickSort(a, l, j);
	if(i < r) quickSort(a, i, r);
}

int findDiffNum(vector <int> &a)
{
	int k = 1;
	quickSort(a, 0, a.size() - 1);
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
