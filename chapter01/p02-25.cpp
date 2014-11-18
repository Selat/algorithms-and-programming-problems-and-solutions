#include <iostream>
#include <vector>

using namespace std;

int findCommon(vector <vector <int> > &a)
{
	vector <int> b(a.size(), 0);
	bool equal = true;
	for(int i = 1; i < a.size(); ++i) {
		equal = equal && (a[i][b[i]] == a[0][b[0]]);
	}
	while(!equal) {
		int min_id = 0;
		for(int i = 0; i < a.size(); ++i) {
			if(a[i][b[i]] < a[min_id][b[min_id]]) {
				min_id = i;
			}
		}
		++b[min_id];
		equal = true;
		for(int i = 1; i < a.size(); ++i) {
			equal = equal && (a[i][b[i]] == a[0][b[0]]);
		}
	}
	return a[0][b[0]];
}

int main()
{
	int n, m;
	vector <vector <int> > a;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		a[i].resize(m);
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	cout << findCommon(a) << endl;
	return 0;
}
