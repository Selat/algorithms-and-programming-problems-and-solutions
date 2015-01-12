#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

/*
 * 8.1.3. Compare the recursive and the (simplest) non-recursive algorithm to com-
 * pute the Fibonacci numbers defined as the sequence
 * F(1) = F(2) = 1,     F(n) = F(n - 1) + F(n - 2).
 */

int f[2] = {0, 1};

int fib1(int n)
{
	if(n >= 2) {
		return fib1(n - 1) + fib1(n - 2);
	} else {
		return f[n];
	}
}

int fib2(int n)
{
	int a = 0, b = 1;
	for(int i = 0; i < n; ++i) {
		a += b;
		b = a - b;
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	auto start = chrono::high_resolution_clock::now();
	fib1(n);
	cout << "Algorithms in O(2^n) time: ";
	auto end = chrono::high_resolution_clock::now();
	cout << fixed << setw(5) << setprecision(2) << std::chrono::duration<double>(end - start).count() << "s" << endl;

	start = chrono::high_resolution_clock::now();
	fib2(n);
	cout << "Algorithms in O(n) time: ";
	end = chrono::high_resolution_clock::now();
	cout << fixed << setw(5) << setprecision(2) << std::chrono::duration<double>(end - start).count() << "s" << endl;
	return 0;
}
