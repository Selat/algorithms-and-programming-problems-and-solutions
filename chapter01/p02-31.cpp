#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector <int> &a, int b)
{
	int i = 0, j = a.size() - 1;
	while(i != j) {
		if(a[i + 1] <= b) {
			++i;
		} else if(a[j - 1] >= b) {
			--j;
		} else {
			// Here (a[i + 1] > b) && (a[j + 1] < b)
			swap(a[i + 1], a[j - 1]);
			++i;
			--j;
		}
	}
}

int main()
{
	int n, b;
	vector <int> a;
	cin >> n >> b;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	rearrange(a, b);

	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
