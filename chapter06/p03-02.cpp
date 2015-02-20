#include <iostream>
#include <vector>

/*
 * 6.3.2. The same problem with an additional requirement: test if the set is empty
 * in constant (i.e., O(1)) time.
 */

using namespace std;

class Set
{
public:
	Set(int n);
	void clear();
	bool contains(int id);
	void add(int id);
	void erase(int id);
	int min();
	bool empty();
private:
	vector <bool> used_;
	int elements_num_;
};

Set::Set(int n) :
	used_(n)
{
}

void Set::clear()
{
	for(int i = 0; i < used_.size(); ++i) {
		used_[i] = false;
	}
}

bool Set::contains(int id)
{
	return used_[id];
}

void Set::add(int id)
{
	if(!used_[id]) {
		++elements_num_;
	}
	used_[id] = true;
}

void Set::erase(int id)
{
	if(used_[id]) {
		--elements_num_;
	}
	used_[id] = false;
}

int Set::min()
{
	for(int i = 0; i < used_.size(); ++i) {
		if(used_[i]) {
			return i;
		}
	}
	return -1;
}

bool Set::empty()
{
	return (elements_num_ == 0);
}

int main()
{
	return 0;
}
