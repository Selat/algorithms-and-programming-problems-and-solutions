#include <iostream>
#include <vector>

using namespace std;

bool contains(const vector <int> &left, const vector <int> &right, const vector <int> &data, int root, int x)
{
	if(root == 0) {
		return false;
	} else {
		int t = root - 1;
		while(((x < data[t]) && (left[t] != 0)) ||
		      ((x > data[t]) && (right[t] != 0))) {
			if(x < data[t]) {
				t = left[t] - 1;
			} else {
				t = right[t] - 1;
			}
		}
		return (data[t] == x);
	}
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
	vector <int> left(n);
	vector <int> right(n);
	vector <int> data(n);
	for(int i = 0; i < n; ++i) {
		cin >> left[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> right[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> data[i];
	}
	if(contains(left, right, data, root, x)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
