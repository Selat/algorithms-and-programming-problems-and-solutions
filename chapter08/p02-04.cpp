#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 * 8.2.4. Write a non-recursive program that prints all the vertices of a binary tree.
 */

struct Tree
{
	int root;
	int n;
	vector <int> l, r;

	void print();
};

void Tree::print()
{
	stack <int> s;
	int id = root;
	s.push(id);
	while(!s.empty()) {
		id = s.top();
		s.pop();
		if(id != -1) {
			cout << (id + 1) << " ";
			s.push(r[id]);
			s.push(l[id]);
		}
	}
	cout << endl;
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
