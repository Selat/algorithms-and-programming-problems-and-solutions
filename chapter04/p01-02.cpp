#include <iostream>
#include <vector>

using namespace std;

/*
 * 4.1.2. Give another sorting algorithm which uses the following invariant
 * relation: “first k elements are sorted” (x[1] <= ... <= x[k]).
 */

void sort(vector <int> &a)
{
	for(int i = 0; i < a.size(); ++i) {
		for(int j = i; (j > 0) && (a[j] < a[j - 1]); --j) {
			swap(a[j], a[j - 1]);
		}
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
