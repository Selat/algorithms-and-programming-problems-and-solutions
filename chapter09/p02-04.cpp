#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
 * 9.2.4. Write a non-recursive algorithm for topological sorting of a directed
 * graph without cycles. (For a recursive algorithm, see p. 113.)
 */


vector <vector <int> > g;
vector <bool> used;
vector <int> ans;

void dfs(int v)
{
	stack <int> s;
	s.push(v);
	while(!s.empty()) {
		int v = s.top();
		used[v] = true;
		bool has_unused = false;
		for(int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if(!used[to]) {
				has_unused = true;
				break;
			}
		}
		if(has_unused) {
			for(int i = 0; i < g[v].size(); ++i) {
				int to = g[v][i];
				if(!used[to]) {
					s.push(to);
				}
			}
		} else {
			ans.push_back(v);
			s.pop();
		}
	}
}

void topsort()
{
	ans.clear();
	for(int i = 0; i < g.size(); ++i) {
		if(!used[i]) {
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());

	for(int i = 0; i < ans.size(); ++i) {
		cout << (ans[i] + 1) << " ";
	}
}

int main()
{

	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	for(int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		--from;
		--to;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	topsort();

	return 0;
}
