#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.2. Count the number of zeros in an array x. (Write a program fragment that
 * does not change the value of x and guarantees that the integer variable k contains the
 * number of zeros among x[1]..x[n].)
 */

int getZerosNum(const vector<int> &x)
{
	int num = 0;
	for(int i = 0; i < x.size(); ++i) {
		if(x[i] == 0) {
			++num;
		}
	}
	return num;
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
	cout << getZerosNum(a) << endl;
	return 0;
}
