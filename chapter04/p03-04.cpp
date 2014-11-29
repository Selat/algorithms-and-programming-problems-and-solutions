#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
 * 4.3.4. The same problem for a polygon: for a given set of points in the plane
 * find a polygon having these points as vertices.
 */

const float eps = 1.0e-7;

bool equal(float a, float b)
{
	return (a - b >= -eps) && (a - b <= eps);
}

struct RelPoint
{
	float angle, dist;
	int id;

	bool operator<(const RelPoint &p) const
	{
		return (angle < p.angle) || (equal(angle, p.angle) && (dist < p.dist));
	}
};

struct Point
{
	float x, y;

	bool operator<(const Point &p) const
	{
		return (x < p.x) || (equal(x, p.x) && (y < p.y));
	}
};

void reorder(vector <Point> &a)
{
	vector <RelPoint> b;
	// a[0] - leftmost point
	sort(a.begin(), a.end());
	for(int i = 1; i < a.size(); ++i) {
		float dx = a[i].x - a[0].x;
		float dy = a[i].y - a[0].y;
		RelPoint tmp;
		tmp.angle = atan2(dy, dx);
		tmp.dist = sqrt(dx * dx + dy * dy);
		tmp.id = i;
		b.push_back(tmp);
	}
	// Sort points according to the angle of vector (p[i] - p[0])
	// If angles are equal, sort according to the distance |p[i] - p[0]|
	sort(b.begin(), b.end());
	vector <Point> ta;
	ta.push_back(a[0]);
	for(int i = 0; i < b.size(); ++i) {
		int id = b[i].id;
		ta.push_back(a[id]);
	}
	a = ta;
}

int main()
{
	int n;
	vector <Point> a;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	reorder(a);
	for(int i = 0; i < n; ++i) {
		cout << a[i].x << " " << a[i].y << endl;
	}
	return 0;
}
