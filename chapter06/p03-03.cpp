#include <iostream>
#include <vector>

/*
 * 6.3.3. The same problem with the following restrictions:
 * min - C,
 * empty - C,
 * clear - Cn,
 * add - C,
 * erase - Cn,
 * contains - C,
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
	int min_element_;
};

Set::Set(int n) :
	used_(n),
	min_element_(n)
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
	if(id < min_element_) {
		min_element_ = id;
	}
	used_[id] = true;
}

void Set::erase(int id)
{
	if(used_[id]) {
		--elements_num_;
	}
	used_[id] = false;
	if(id == min_element_) {
		while(min_element_ < used_.size()) {
			if(used_[min_element_]) {
				break;
			}
			++min_element_;
		}
	}
}

int Set::min()
{
	if(min_element_ == used_.size()) {
		return -1;
	} else {
		return min_element_;
	}
}

bool Set::empty()
{
	return (elements_num_ == 0);
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
