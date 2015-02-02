#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
 * 9.2.7. Modify the algorithm in such a way that it can be applied to any graph.
 * The algorithm should either find a cycle (if it exists) or perform a topological sort (if
 * there are no cycles).
 */

int n;
vector <vector <int> > g;
vector <bool> used;
vector <int> ans;
vector <char> cl;
vector <int> p;
int cycle_st, cycle_end;

bool dfs2(int v)
{
	cl[v] = 1;
	for(size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if(cl[to] == 0) {
			p[to] = v;
			if(dfs2(to)) {
				return true;
			}
		} else if(cl[to] == 1) {
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}


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
	// Check if cycle exists
	p.assign(n, -1);
	cl.assign(n, 0);
	cycle_st = -1;
	for(int i = 0; i < n; ++i) {
		if(dfs2(i)) break;
	}
	if(cycle_st == -1) {
		cout << "Acyclic" << endl;
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

	} else {
		cout << "Cyclic" << endl;
		vector <int> cycle;
		cycle.push_back(cycle_st);
		for(int v = cycle_end; v != cycle_st; v = p[v]) {
			cycle.push_back(v);
		}
		cycle.push_back(cycle_st);
		reverse(cycle.begin(), cycle.end());
		for(int i = 0; i < cycle.size(); ++i) {
			cout << (cycle[i] + 1) << " ";
		}
	}
}

int main()
{

	int m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	for(int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		--from;
		--to;
		g[from].push_back(to);
	}

	topsort();

	return 0;
}
