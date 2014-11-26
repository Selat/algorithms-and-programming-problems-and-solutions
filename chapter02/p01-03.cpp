#include <iostream>
#include <vector>

using namespace std;

bool nextSubset(vector <bool> &a)
{
	int i = 0;
	while(a[i] && (i < a.size())) ++i;
	for(int j = 0; j < i; ++j) {
		a[j] = false;
	}
	if(i < a.size()) {
		a[i] = true;
		return false;
	} else {
		return true;
	}
}

void printSubset(const vector <bool> &used)
{
	cout << "{";
	bool prev_printed = false;
	for(int i = 1; i <= used.size(); ++i) {
		if(used[i - 1]) {
			if(prev_printed) {
				cout << ", ";
			}
			cout << i;
			prev_printed = true;
		}
	}
	cout << "}" << endl;
}

void printSubsets(int k)
{
	vector <bool> used(k, false);
	bool is_last = false;
	while(!is_last) {
		printSubset(used);
		is_last |= nextSubset(used);
	}
}

int main()
{
	int k;
	cin >> k;
	printSubsets(k);
	return 0;
}
