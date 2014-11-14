#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.9. (Communicated by A.L. Brudno.) A rectangular field m × n contains
 * mn squares. Some squares are marked as black. It is known that black squares arne
 * grouped into several disjoint rectangles (no common sides). Assuming that the
 * colors of squares are represented as array [1..m] of array [1..n] of Boolean;
 * count the number of rectangles. The number of operations should be of order mn.
 */

int findRectanglesNum(const vector <vector <bool> > &a)
{
	int k = 0;
	// just count the number of upper left corners of rectangles
	for(int i = 0; i < a.size(); ++i) {
		for(int j = 0; j < a[i].size(); ++j) {
			if(a[i][j]
			   && ((j == 0) || (!a[i][j - 1]))
			   && ((i == 0) || (!a[i - 1][j]))) {
				++k;
			}
		}
	}
	return k;
}

int main()
{
	int n, m;
	vector <vector <bool> > a;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		a[i].resize(m);
		for(int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			a[i][j] = (c == '1');
		}
	}

	cout << findRectanglesNum(a) << endl;
	return 0;
}
