#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

/*
 * 8.1.4. A convex polygon with n vertices is given (by a list of coordinates of its
 * vertices). It is cut into triangles by non-intersecting diagonals. To do this, we need
 * exactly n − 3 diagonals (proof by induction over n). The cost of the triangulation
 * is defined as the total length of all the diagonals used. Find the minimal cost of the
 * triangulation. The number of operations should be limited by a polynomial of n.
 * (This requirement excludes exhaustive search, since the number of possibilities is
 * not bounded by any polynomial.)
 *
 * The solution uses the following relation
 * a(i, j) = min{a(i, k) + a(k, j) + dist(i, k) + dist(k, j)}
 * where a(i, j) - the minimal cost of triangulation of the polygon that consists of points
 * int the interval [i, j].
 */

struct Point
{
	double x, y;
	double dist(const Point &p)
	{
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
};

const int MAXN = 100;
const int INF = INT_MAX;

double a[MAXN][MAXN];

double solve(vector <Point> &points)
{
	for(int i = 0; i < points.size(); ++i) {
		for(int j = 0; j < points.size(); ++j) {
			a[i][j] = -5.0;
		}
		if(i + 1 < points.size())
			a[i][i + 1] = 0;
		if(i + 2 < points.size())
			a[i][i + 2] = 0;
	}
	stack <pair <int, int> > s;
	s.push(make_pair(0, points.size() - 1));
	while(!s.empty()) {
		int l = s.top().first;
		int r = s.top().second;
		if(a[l][r] < -1.0) {
			bool can_compute = true;
			double val = -1.0;
			for(int k = l + 1; k < r; ++k) {
				if(a[l][k] < -1.0) {
					can_compute = false;
					s.push(make_pair(l, k));
				}
				if(a[k][r] < -1.0) {
					can_compute = false;
					s.push(make_pair(k, r));
				}
				double dist = 0.0;
				if(k > l + 1) {
					dist += points[l].dist(points[k]);
				}
				if(k < r - 1) {
					dist += points[r].dist(points[k]);
				}
				double total = a[l][k] + a[k][r] + dist;
				if((val < 0.0) || (val > total)) {
					val = total;
				}
			}
			if(can_compute) {
				a[l][r] = val;
			}
		} else {
			s.pop();
		}
	}
	return a[0][points.size() - 1];
}

int main()
{
	int n;
	cin >> n;
	vector <Point> points(n);
	for(int i = 0; i < n; ++i) {
		cin >> points[i].x >> points[i].y;
	}
	cout << solve(points) << endl;
	return 0;
}
