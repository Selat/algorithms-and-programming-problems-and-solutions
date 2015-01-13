#include <iostream>
#include <stack>

using namespace std;

/*
 * 8.2.1. Write a non-recursive program that prints the sequence of moves for
 * Towers of Hanoi problem.
 */

struct Move
{
	int end, from, to;
};

void printMoves(int n)
{
	stack <Move> moves;
	Move move;
	move.end = n;
	move.from = 1;
	move.to = 2;
	moves.push(move);
	while(!moves.empty()) {
		move = moves.top();
		moves.pop();
		if(move.end == 1) {
			cout << move.end << ": " << move.from << " -> " << move.to << endl;
		} else {
			int cell = 6 - (move.from + move.to);
			move.end = move.end - 1;
			int to = move.to;
			move.to = cell;
			moves.push(move);
			cout << move.end << ": " << move.from << " -> " << to << endl;
			move.from = cell;
			move.to = to;
			moves.push(move);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	printMoves(n);
	return 0;
}
