#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/*
 * 6.3.5. The same problem with the following restrictions:
 * The memory size is limited by Cn.
 * min - Cn,
 * size - C,
 * clear - C,
 * add - C,
 * erase - Cn,
 * contains - Cn,
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
private:
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
	data_[size_++] = val;
}

void Set::erase(int val)
{
	int id = -1;
	for(int i = 0; i < size_; ++i) {
		if(data_[i] == val) {
			id = i;
		}
	}
	if(id >= 0) {
		--size_;
		for(int i = id; i < size_; ++i) {
			data_[i] = data_[i + 1];
		}
	}
}

int Set::min()
{
	int min = INT_MAX;
	for(int i = 0; i < size_; ++i) {
		if(data_[i] < min) {
			min = data_[i];
		}
	}
	return min;
}

int Set::size()
{
	return size_;
}

int Set::get(int id)
{
	return data_[id];
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
