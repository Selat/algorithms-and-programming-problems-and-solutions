#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 4.3.3. Assume that n points in the plane are given. Find a polygonal arc with
 * n − 1 sides whose vertices are the given points, and whose sides do not intersect.
 * (Adjacent sides may form a 180 ◦ angle.) The number of operations should be of
 * order n * log n.
 */

void reorder(vector <pair <float, float> > &a)
{
	sort(a.begin(), a.end());
}

int main()
{
	int n;
	vector <pair <float, float> > a;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	reorder(a);
	for(int i = 0; i < n; ++i) {
		cout << a[i].first << " " << a[i].second << endl;
	}
	return 0;
}
