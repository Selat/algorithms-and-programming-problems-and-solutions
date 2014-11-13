#include <iostream>

using namespace std;

/*
 * 1.1.27. Write a program that prints the decimal representation of a positive
 * integer n in reverse. (For n = 173, the program should print 371.)
 */

void printNum(int n)
{
	while(n != 0) {
		cout << n % 10;
		n /= 10;
	}
}

int main()
{
	int n;
	cin >> n;
	printNum(n);
	return 0;
}
