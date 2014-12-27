#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.3.3. Print all sequences of length n that contain k ones and n − k zeros. (Each
 * of them should be printed once.)
 */

vector <int> a;

void printSequences(int n, int k, int cur = 0, int ones_num = 0)
{
	if(cur == n) {
		for(int i = 0; i < a.size(); ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	} else {
		if(ones_num < k) {
			a[cur] = 1;
			printSequences(n, k, cur + 1, ones_num + 1);
		}
		if(n - cur > k - ones_num) {
			a[cur] = 0;
			printSequences(n, k, cur + 1, ones_num);
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	a.resize(n);
	printSequences(n, k);
	return 0;
}
