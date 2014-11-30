#include <iostream>
#include <vector>

using namespace std;

/*
 * 4.4.3. Rearrange the array a[1]..a[n] in such a way that all even elements
 * precede all odd elements (not changing the order inside each of the two groups).
 */

void rearrange(vector <int> &a)
{
	vector <int> b;
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] % 2 == 0) {
			b.push_back(a[i]);
		}
	}
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] % 2 != 0) {
			b.push_back(a[i]);
		}
	}
	a = b;
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
	rearrange(a);
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
