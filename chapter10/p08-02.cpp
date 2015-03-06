#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * 10.8.2. Solve the previous problem with the additional restriction: the space
 * used should be proportional to the length of Y.
 */

class SuffixTree
{
public:
	SuffixTree(const string &s);
	bool match(const string &s);
private:
	vector <map <char, pair <int, string> > > g_;
};

SuffixTree::SuffixTree(const string &s)
{
	g_.push_back(map <char, pair <int, string> > ());
	for(int i = 0; i < s.length(); ++i) {
		int j = i;
		int vid = 0;
		while(j < s.length()) {
			auto it = g_[vid].find(s[j]);
			if(it == g_[vid].end()) {
				it = g_[vid].insert(make_pair(s[j], make_pair(g_.size(), s.substr(j, s.length() - j)))).first;
				g_.push_back(map <char, pair <int, string> > ());
				j = s.length();
			} else {
				string &s2 = it->second.second;
				int id = 0;
				int start = j;
				while((id < s2.length()) && (s2[id] == s[j])) {
					++id;
					++j;
				}
				if(j < s.length()) {
					if(id < s2.length()) {
						g_.push_back(map <char, pair <int, string> > ());
						int id1 = it->second.first;
						g_[id1].insert(make_pair(s2[id], make_pair(g_.size(), s2.substr(id, s2.length() - id))));
						g_.push_back(map <char, pair <int, string> > ());
						int lid = g_.size() - 1;
						it = g_[id1].insert(make_pair(s[j], make_pair(g_.size(), s.substr(j, s.length() - j)))).first;
						s2 = s2.substr(0, id);
						vid = lid;
					} else {
						vid = it->second.first;
					}
				}
			}
		}
	}
}

bool SuffixTree::match(const string &s)
{
	int vid = 0;
	bool matches = true;
	for(int i = 0; i < s.length();) {
		auto it = g_[vid].find(s[i]);
		if(it == g_[vid].end()) {
			matches = false;
			break;
		} else {
			string &s2 = it->second.second;
			int id = 0;
			while((id < s2.length()) && (s2[id] == s[i])) {
				++id;
				++i;
			}
			if((i < s.length()) && (id < s.length())) {
				matches = false;
				break;
			} else if(i < s.length()) {
				vid = it->second.first;
			}
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
