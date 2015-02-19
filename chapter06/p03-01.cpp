#include <iostream>
#include <vector>

/*
 * 6.3.1. Using O(n) space (=space proportional to n), store a subset of {1, . . . , n}.
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
	vector <bool> m_used;
};

Set::Set(int n) :
	m_used(n)
{
}

void Set::clear()
{
	for(int i = 0; i < m_used.size(); ++i) {
		m_used[i] = false;
	}
}

bool Set::contains(int id)
{
	return m_used[id];
}

void Set::add(int id)
{
	m_used[id] = true;
}

void Set::erase(int id)
{
	m_used[id] = false;
}

int Set::min()
{
	for(int i = 0; i < m_used.size(); ++i) {
		if(m_used[i]) {
			return i;
		}
	}
	return -1;
}

bool Set::empty()
{
	for(int i = 0; i < m_used.size(); ++i) {
		if(m_used[i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	return 0;
}
