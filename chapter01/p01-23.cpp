#include <iostream>

using namespace std;

/*
 * 1.1.23. Solve the preceding problem taking into account the following fact: any
 * composite number N has a factor not exceeding sqrt(N) .
 */

void factorize(int n)
{
	// invariant: the product of k and all printed numbers is equal to n.
	int k = n;
	int i = 2;
	while(k != 1) {
		while(k % i != 0) {
			if(i * i >= k) {
				i = k;
			} else {
				++i;
			}
		}
		k /= i;
		cout << i << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	factorize(n);
	return 0;
}
