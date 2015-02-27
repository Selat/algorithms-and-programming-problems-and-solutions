#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/*
 * 6.4.1. Implement a data structure that has the same set of operations as an array
 * of length n, namely,
 * • initialize;
 * • put x in the i-th cell;
 * • find the contents of the i-th cell;
 * as well as the operation
 * • find the index of the minimal element
 * (or one of the minimal elements). Any operation should run in time C log n (except
 * for the initialization, which should run in time Cn).
 */

class Heap
{
public:
	Heap(int n);
	int min();
	int get(int id);
	void set(int id, int val);
	void print()
	{
		for(int i = 1; i < tree_.size(); ++i) {
			cout << tree_[i] << " ";
		}
		cout << endl;
	}
private:

	vector <int> tree_;
	vector <int> data_;
	int size_;
};

Heap::Heap(int n) :
	tree_(n + 1),
	data_(n + 1),
	size_(0)
{
	for(int i = 1; i <= n; ++i) {
		set(i, INT_MAX);
	}
}

int Heap::min()
{
	return tree_[1];
}

int Heap::get(int id)
{
	return data_[id];
}

void Heap::set(int id, int val)
{
	data_[id] = val;
	tree_[id] = data_[id];
	if(2 * id < tree_.size()) {
		tree_[id] = ::min(tree_[id], tree_[id * 2]);
	}
	if(2 * id + 1 < tree_.size()) {
		tree_[id] = ::min(tree_[id], tree_[id * 2 + 1]);
	}
	int p = id / 2;
	while(p > 0) {
		tree_[p] = ::min(data_[p], tree_[p * 2]);
		if(p * 2 + 1 < tree_.size()) {
			tree_[p] = ::min(tree_[p], tree_[p * 2 + 1]);
		}
		p /= 2;
	}
}

int main()
{
	int n, tmp, id;
	cin >> n;
	Heap h(n);
	for(int i = 0; i < n; ++i) {
		cin >> id >> tmp;
		h.set(id, tmp);
		cout << h.min() << endl;
		h.print();
	}
	return 0;
}
