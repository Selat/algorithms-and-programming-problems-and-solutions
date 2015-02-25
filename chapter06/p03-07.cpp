#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * 6.3.7. Find all the vertices of a directed graph that can be reached from a given
 * vertex along the graph edges. The program should run in time Cm, where m is the
 * total number of edges leaving the reachable vertices.
 */

void dfs(const vector <vector <int> > &g, int v)
{
	queue <int> q;
	vector <bool> used(g.size(), false);
	q.push(v);
	used[v] = true;
	cout << v + 1 << " ";
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int i = 0; i < g[v].size(); ++i) {
			if(!used[g[v][i]]) {
				q.push(g[v][i]);
				used[g[v][i]] = true;
				cout << g[v][i] + 1 << " ";
			}
		}
	}
	cout << endl;
}

int main()
{
	vector <vector <int> > g;
	int n, m, from, to;
	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; ++i) {
		cin >> from >> to;
		--from; --to;
		g[from].push_back(to);
	}
	dfs(g, 0);
	return 0;
}
