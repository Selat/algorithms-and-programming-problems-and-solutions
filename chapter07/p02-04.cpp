#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.2.4. Write a program that finds the height of a tree. (The root of a tree has
 * depth 0, its sons have depth 1, its grandsons have depth 2, etc. The height of a tree is
 * the maximal depth of its vertices.)
 */

struct Tree
{
	int root;
	int n;
	vector <int> l, r;

	int getHeight();
private:
	int _getHeight(int id);
};

int Tree::getHeight()
{
	return _getHeight(root);
}

int Tree::_getHeight(int id)
{
	if(id == -1) {
		return 0;
	} else {
		return 1 + max(_getHeight(l[id]), _getHeight(r[id]));
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
	cout << t.getHeight() << endl;
	return 0;
}
