#include <iostream>
#include <vector>

using namespace std;

/*
 * 8.3.1. Write a non-recursive program to compute f in the general case.
 * f(0) = a,
 * f(x) = h(x, f(l(x))), x > 0,
 * here a is some number, while h and l are known functions. We assume that
 * for any x the sequence x, l(x), l(l(x)), ... reaches 0.
 */

const int a = 0;

int l(int x)
{
	return x - 1;
}

int h(int x, int y)
{
	return x + y;
}

int f(int x)
{
	if(x != 0) {
		vector <int> val;
		while(x != 0) {
			val.push_back(x);
			x = l(x);
		}
		int res = a;
		for(int i = val.size() - 1; i >= 0; --i) {
			res = h(val[i], res);
		}
		return res;
	} else {
		return a;
	}
}

int main()
{
	int x;
	cin >> x;
	cout << f(x) << endl;
	return 0;
}
