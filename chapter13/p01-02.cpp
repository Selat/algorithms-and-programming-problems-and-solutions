#include <iostream>
#include <functional>
#include <string>
#include <vector>

using namespace std;

/*
 * 13.1.2. Write the programs for membership test, adding and deleting elements.
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
	int dist(int a, int b)
	{
		return (b - a + data_.size()) % data_.size();
	}

	vector<bool> used_;
	vector <string> data_;
};

HashTable::HashTable(int n) :
	used_(n, false), data_(n)
{
}

bool HashTable::exists(const string &s)
{
	int id = hash(s);
	while((used_[id]) && (data_[id] != s)) {
		id = (id + 1) % data_.size();
	}
	return used_[id] && (data_[id] == s);
}

void HashTable::insert(const string &s)
{
	int id = hash(s);
	bool ok = false;
	while(used_[id] && (data_[id] != s)) {
		id = (id + 1) % data_.size();
	}
	if(!used_[id]) {
		data_[id] = s;
		used_[id] = true;
	}
}

void HashTable::erase(const string &s)
{
	int id = hash(s);
	int start_id = id;
	bool found = false;
	while(used_[id] && (data_[id] != s)) {
		id = (id + 1) % data_.size();
	}
	if(used_[id] && (data_[id] == s)) {
		used_[id] = false;
		int gap = id;
		id = (id + 1) % data_.size();
		while(used_[id]) {
			int thash = hash(data_[id]);
			if(thash == id) {
				// data_[id] is on it's original place, so we don't have to move it.
			} else if(dist(thash, id) < dist(gap, id)) {
				// gap ... h(val[i]) ... i
			} else {
				used_[gap] = true;
				data_[gap] = data_[id];
				used_[id] = false;
				gap = id;
			}
			id = (id + 1) % data_.size();
		}
	}
}

int HashTable::hash(const string &s)
{
	std::hash <std::string> fn;
	return fn(s) % data_.size();
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
