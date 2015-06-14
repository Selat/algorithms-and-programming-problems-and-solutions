#include <iostream>
#include <vector>

using namespace std;

bool contains(const vector <int> &left, const vector <int> &right, vector <int> &data, int root, int x)
{
	int t = root;
	data[0] = x;
	while(x != data[t]) {
		if(x < data[t]) {
			t = left[t];
		} else {
			t = right[t];
		}
	}
	return (t != 0);
}

/*
  Example:
      2
     / \
    1   3
  3 3 1
  2 0 0
  3 0 0
  2 1 3
*/

int main()
{
	int n, x, root;
	cin >> n >> x >> root;
	vector <int> left(n + 1);
	vector <int> right(n + 1);
	vector <int> data(n + 1);
	for(int i = 0; i < n; ++i) {
		cin >> left[i + 1];
	}
	for(int i = 0; i < n; ++i) {
		cin >> right[i + 1];
	}
	for(int i = 0; i < n; ++i) {
		cin >> data[i + 1];
	}
	if(contains(left, right, data, root, x)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
