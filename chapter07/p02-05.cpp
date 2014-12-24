#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.2.5. Write a program which for a given n counts all the vertices of depth n in
 * a given tree.
 */

struct Tree
{
	int root;
	int n;
	vector <int> l, r;

	int getNum(int n);
private:
	int _getNum(int id, int depth, int n);
};

int Tree::getNum(int n)
{
	return _getNum(root, 0, n);
}

int Tree::_getNum(int id, int depth, int n)
{
	if(id == -1) {
		return 0;
	} else if(depth == n) {
		cout << id + 1 << " ";
		return 1;
	} else {
		return _getNum(l[id], depth + 1, n) + _getNum(r[id], depth + 1, n);
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
	int n;
	cin >> t >> n;
	int num = t.getNum(n);
	cout << endl << num << endl;
	return 0;
}
