#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * 10.8.1. The program gets the input string Y and can process it (no time or space
 * limits yet). Then it gets the string X of length n and must report whether X is a
 * substring of Y . The number of operations in processing X must be O(n) (it must not
 * exceed cn where c may depend on the alphabet). Construct such a program.
 */

class SuffixTree
{
public:
	SuffixTree(const string &s);
	bool match(const string &s);
private:
	vector <map <char, int> > g_;
};

SuffixTree::SuffixTree(const string &s)
{
	g_.push_back(map <char, int> ());
	for(int i = 0; i < s.length(); ++i) {
		int vid = 0;
		for(int j = i; j < s.length(); ++j) {
			auto it = g_[vid].find(s[j]);
			if(it == g_[vid].end()) {
				it = g_[vid].insert(make_pair(s[j], g_.size())).first;
				g_.push_back(map <char, int> ());
			}
			vid = it->second;
		}
	}
}

bool SuffixTree::match(const string &s)
{
	int vid = 0;
	bool matches = true;
	for(int i = 0; i < s.length(); ++i) {
		auto it = g_[vid].find(s[i]);
		if(it == g_[vid].end()) {
			matches = false;
			break;
		} else {
			vid = it->second;
		}
	}
	return matches;
}

int main()
{
	string y, x;
	int n;
	cin >> y >> n;
	SuffixTree t(y);
	for(int i = 0; i < n; ++i) {
		cin >> x;
		if(t.match(x)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
