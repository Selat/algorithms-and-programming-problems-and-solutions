#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
 * 8.2.7. Write a non-recursive version of Hoare’s quicksort algorithm. How do we
 * guarantee that the size of the stack does not exceed C log n, where n is the number
 * of elements to be sorted?
 */

void quickSort(vector <int> &a)
{
	stack <pair <int, int> > s;
	s.push(make_pair(0, a.size() - 1));
	while(!s.empty()) {
		int l = s.top().first;
		int r = s.top().second;
		s.pop();
		int i = l, j = r, pivot = a[(l + r) / 2];
		while(i <=j) {
			while(a[i] < pivot) ++i;
			while(a[j] > pivot) --j;
			if(i <= j) {
				swap(a[i], a[j]);
				++i;
				--j;
			}
		}
		if(j > l) {
			s.push(make_pair(l, j));
		}
		if(i < r) {
			s.push(make_pair(i, r));
		}
	}
}

int main()
{
	srand(time(NULL));
	vector <int> a;
	int n;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		a[i] = rand();
	}
	vector <int> b = a;
	sort(a.begin(), a.end());
	cout << "end of sort!" << endl;
	quickSort(b);
	bool ok = true;
	for(int i = 0; i < n; ++i) {
		if(a[i] != b[i]) {
			cerr << "Incorrect for: " << i << endl;
			ok = false;
			break;
		}
	}
	if(ok) {
		cout << "Algorithm is correct!" << endl;
	}
	return 0;
}
