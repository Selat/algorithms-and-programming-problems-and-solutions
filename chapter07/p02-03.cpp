#include <iostream>
#include <vector>

using namespace std;

/*
 * 7.2.3. Write a program that counts the leaves in a tree.
 */

struct Tree
{
	int root;
	int n;
	vector <int> l, r;

	int getLeavesNum();
private:
	int _getLeavesNum(int id);
};

int Tree::getLeavesNum()
{
	return _getLeavesNum(root);
}

int Tree::_getLeavesNum(int id)
{
	if(id == -1) {
		return 0;
	} else if((l[id] == -1) && (r[id] == -1)) {
		return 1;
	} else {
		return _getLeavesNum(l[id]) + _getLeavesNum(r[id]);
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
	cout << t.getLeavesNum() << endl;
	return 0;
}
