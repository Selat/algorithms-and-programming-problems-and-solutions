#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 4.3.2. Suppose that n closed intervals [a[i], b[i]] on the real line are given
 * (i = 1..n). Find the maximal k such that there exists a point covered by k intervals
 * (the maximal number of “layers”). The number of operations should be of order n * log n.
 */

int getCommonNum(const vector <pair <float, float> > &a)
{
	vector <pair <float, int> > b;
	// Push all coordinates into one array and then sort it.
	// Each left endpoint is associated with -1,
	// and each right endpoint associated with 1.
	// Therefore every left endpoint of some interval
	// will always preceed right endpoint of this interval.
	for(int i = 0; i < a.size(); ++i) {
		b.push_back(make_pair(a[i].first, -1));
		b.push_back(make_pair(a[i].second, 1));
	}
	sort(b.begin(), b.end());
	int num = 0;
	int max_num = 0;
	for(int i = 0; i < b.size(); ++i) {
		num -= b[i].second;
		if(num > max_num) {
			max_num = num;
		}
	}
	return max_num;
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
	cout << getCommonNum(a) << endl;
	return 0;
}
