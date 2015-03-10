#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <list>

using namespace std;

/*
 * 13.2.1. Suppose the values of hash function h are 1..k. For any number j in
 * 1..k, consider a list of all set elements z such that h(z) = j. Let us store those k
 * lists using the variables
 * Content: array [1..n] of T;
 * Next: array [1..n] of 1..n;
 * Free: 1..n;
 * Top: array [1..k] of 1..n;
 * in the same way as we did for k stacks of limited size (p. 87). Write the corresponding
 * procedures. (Please note that deletion is now easier than in the open addressing case.)
 */

class HashTable
{
public:
	HashTable(int n);
	bool exists(const string &s);
	void insert(const string &s);
	void erase(const string &s);
private:
	int hash(const string &s);
	int getFreeCell();
	void freeCell(int id);

	vector <int> top_;
	vector <int> next_;
	vector <string> data_;
	int free_id_;
};

HashTable::HashTable(int n) :
	data_(n), next_(n), top_(n, -1)
{
	for(int i = 0; i + 1 < n; ++i) {
		next_[i] = i + 1;
	}
	next_[n - 1] = -1;
	free_id_ = 0;
}

bool HashTable::exists(const string &s)
{
	int id = top_[hash(s)];
	bool found = false;
	while(id >= 0) {
		if(s == data_[id]) {
			found = true;
			break;
		}
		id = next_[id];
	}
	return found;
}

void HashTable::insert(const string &s)
{
	int id = hash(s);
	if(!exists(s)) {
		int new_id = getFreeCell();
		data_[new_id] = s;
		if(top_[id] == -1) {
			top_[id] = new_id;
		} else {
			while(next_[id] != -1) {
				id = next_[id];
			}
			next_[id] = new_id;
		}
	}
}

void HashTable::erase(const string &s)
{
	int id = hash(s);
	if(top_[id] >= 0) {
		if(data_[top_[id]] == s) {
			int tnext = next_[top_[id]];
			freeCell(top_[id]);
			top_[id] = tnext;
		} else {
			id = top_[id];
			while(next_[id] != -1) {
				if(data_[next_[id]] == s) {
					int tnext = next_[next_[id]];
					freeCell(next_[id]);
					next_[id] = tnext;
					break;
				}
			}
		}
	}
}

int HashTable::hash(const string &s)
{
	std::hash <std::string> fn;
	return fn(s) % data_.size();
}

int HashTable::getFreeCell()
{
	int res = free_id_;
	free_id_ = next_[free_id_];
	next_[res] = -1;
	return res;
}

void HashTable::freeCell(int id)
{
	next_[id] = free_id_;
	free_id_ = id;
}

int main()
{
	int n, m, type;
	string s;
	cin >> n >> m;
	HashTable h(2 * n);
	for(int i = 0; i < m; ++i) {
		cin >> type >> s;
		switch(type) {
		case 1:
			h.insert(s);
			break;
		case 2:
			if(h.exists(s)) {
				cout << "Exists" << endl;
			} else {
				cout << "Doesn't exist" << endl;
			}
			break;
		case 3:
			h.erase(s);
			break;
		default:
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}
