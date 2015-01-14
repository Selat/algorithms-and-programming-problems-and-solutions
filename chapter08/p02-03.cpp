#include <iostream>
#include <stack>

using namespace std;

/*
 * 8.2.3. In the recursive program that prints a decimal number (7.1.6), replace the
 * recursion by a stack.
 */

void print(int n)
{
	stack <int> s;
	s.push(n % 10);
	n /= 10;
	while(n > 0) {
		s.push(n % 10);
		n /= 10;
	}
	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main()
{
	int n;
	cin >> n;
	print(n);
	return 0;
}
