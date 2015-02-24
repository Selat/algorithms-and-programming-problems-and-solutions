#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/*
 * 6.3.6. The same problem with the following restrictions:
 * The memory size is limited by Cn.
 * min - C,
 * size - C,
 * clear - C,
 * add - C*n,
 * erase - C*n,
 * contains - C*log(n),
 * get - C
 */

class Set
{
public:
	Set(int n);
	void clear();
	bool contains(int id);
	void add(int id);
	void erase(int id);
	int min();
	int size();
	int get(int id);
	void print();
private:
	int getId(int val);

	int size_;
	vector <int> data_;
};

Set::Set(int n) :
	data_(n),
	size_(0)
{
}

void Set::clear()
{
	size_ = 0;
}

bool Set::contains(int val)
{
	for(int i = 0; i < size_; ++i) {
		if(data_[i] == val) {
			return true;
		}
	}
	return false;
}

void Set::add(int val)
{
	int id = getId(val);
	for(int i = size_ - 1; i >= id; --i) {
		data_[i + 1] = data_[i];
	}
	data_[id] = val;
	++size_;
}

void Set::erase(int val)
{
	int id = getId(val);
	if(id >= 0) {
		--size_;
		for(int i = id; i < size_; ++i) {
			data_[i] = data_[i + 1];
		}
	}
}

int Set::min()
{
	if(size_ > 0) {
		return data_[0];
	} else {
		return INT_MAX;
	}
}

int Set::size()
{
	return size_;
}

int Set::get(int id)
{
	return data_[id];
}

int Set::getId(int val)
{
	int l = 0, r = size_ - 1;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(data_[m] > val) {
			r = m - 1;
		} else {
			l = m;
		}
	}
	return l;
}

void Set::print()
{
	for(int i = 0; i < size_; ++i) {
		cout << data_[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n, num_add, num_erase, id;
	cin >> n >> num_add >> num_erase;
	Set set(n);
	for(int i = 0; i < num_add; ++i) {
		cin >> id;
		set.add(id);
		cout << set.min() << endl;
	}
	for(int i = 0; i < num_erase; ++i) {
		cin >> id;
		set.erase(id);
		cout << set.min() << endl;
	}
	return 0;
}
