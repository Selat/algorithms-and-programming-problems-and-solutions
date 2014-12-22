#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.2.2. Write a program that counts all the vertices in a given tree.
 */

struct Tree
{
	int root;
	int n;
	vector <int> l, r;

	int getVerteciesNum();
private:
	int _getVerteciesNum(int id);
};

int Tree::getVerteciesNum()
{
	return _getVerteciesNum(root);
}

int Tree::_getVerteciesNum(int id)
{
	if(id == -1) {
		return 0;
	} else {
		return _getVerteciesNum(l[id]) + _getVerteciesNum(r[id]) + 1;
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

int main()
{
	Tree t;
	cin >> t;
	cout << t.getVerteciesNum() << endl;
	return 0;
}
