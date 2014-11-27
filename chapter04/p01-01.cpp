#include <iostream>
#include <vector>

using namespace std;

/*
 * 4.1.1. Let a[1], ... , a[n] be an array of numbers (say, integers). Construct the
 * array b[1], ... , b[n] that contains the same numbers in increasing order:
 * b[1] <= ... <= b[n].
 */

void sort(vector <int> &a)
{
	for(int i = 0; i < a.size() - 1; ++i) {
		int min_id = i;
		for(int j = i; j < a.size(); ++j) {
			if(a[j] < a[min_id]) {
				min_id = j;
			}
		}
		swap(a[min_id], a[i]);
	}
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
	sort(a);
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
