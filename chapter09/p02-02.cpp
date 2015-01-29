#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 9.2.2. Write an algorithm for depth-first search.
 */


vector <vector <int> > g;
vector <bool> used;

void dfs(int id)
{
	used[id] = true;
	cout << id + 1 << " ";
	for(int i = 0; i < g[id].size(); ++i) {
		if(!used[g[id][i]]) {
			dfs(g[id][i]);
		}
	}
}

int main()
{

	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.assign(n, false);
	for(int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		--from;
		--to;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	dfs(0);

	cout << endl;

	return 0;
}
