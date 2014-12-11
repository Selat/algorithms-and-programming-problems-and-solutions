
#include <iostream>
#include <queue>

using namespace std;

queue <int> q2, q3, q5;

void printAndAdd(int x)
{
	cout << x << " ";
	q2.push(x * 2);
	q3.push(x * 3);
	q5.push(x * 5);
}

void remove(queue <int> &q, int x)
{
	if(q.front() == x) {
		q.pop();
	}
}

int main()
{
	int n;
	cin >> n;
	printAndAdd(1);
	for(int k = 1; k < n; ++k) {
		int x = min(q2.front(), min(q3.front(), q5.front()));
		printAndAdd(x);
		remove(q2, x);
		remove(q3, x);
		remove(q5, x);
	}
	return 0;
}
