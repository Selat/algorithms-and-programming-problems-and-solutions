#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.2.6. Write a program that prints all vertices (one time each).
 */

struct Tree
{
	int root;
	int n;
	vector <int> l, r;

	void print();
private:
	void _print(int id);
};

void Tree::print()
{
	_print(root);
	cout << endl;
}

void Tree::_print(int id)
{
	if(id != -1) {
		cout << (id + 1) << " ";
		_print(l[id]);
		_print(r[id]);
	}
}

istream& operator>>(istream& in, Tree& t)
{
	in >> t.n;
	in >> t.root;
	--t.root;
	t.l.resize(t.n);
	t.r.resize(t.n);
	for(int i = 0; i < t.n; ++i) {
		in >> t.l[i];
		--t.l[i];
	}
	for(int i = 0; i < t.n; ++i) {
		in >> t.r[i];
		--t.r[i];
	}
	return in;
}

/*
  10 1
  2 4 6 8 10 0 0 0 0 0
  3 5 7 9 0 0 0 0 0 0
*/

int main()
{
	Tree t;
	cin >> t;
	t.print();
	return 0;
}
