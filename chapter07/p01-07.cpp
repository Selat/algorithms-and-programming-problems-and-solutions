#include <iostream>

using namespace std;

/*
 * 7.1.7. The “Towers of Hanoi” puzzle consists of three vertical sticks and N rings
 * of different sizes. The rings are put on one of the sticks in such a way that larger rings
 * are beneath smaller ones. We are to move this tower onto another stick one ring at a
 * time. While moving the rings from one stick to another, we are not permitted to put
 * a larger ring onto a smaller one. Write a program that shows the list of movements
 * required to solve the problem.
 */

void printMoves(int end, int from, int to)
{
	if(end == 1) {
		cout << end << ": " << from << " -> " << to << endl;
	} else {
		int cell = 6 - (from + to);
		printMoves(end - 1, from, cell);
		cout << end << ": " << from << " -> " <<  to << endl;
		printMoves(end - 1, cell, to);
	}
}

int main()
{
	int n;
	cin >> n;
	printMoves(n, 1, 2);
	return 0;
}
