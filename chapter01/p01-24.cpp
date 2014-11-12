#include <iostream>

using namespace std;

/*
 * 1.1.24. Check whether a given number n > 1 is prime.
 */

bool isPrime(int n)
{
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	if(isPrime(n)) {
		cout << "Prime!" << endl;
	} else {
		cout << "Not a prime!" << endl;
	}
	return 0;
}
