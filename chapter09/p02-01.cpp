#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 9.2.1. Find an algorithm that performs breadth-first search in time Cm, where
 * m is the total number of outgoing edges of all reachable vertices.
 */


void bfs(const vector <vector <int> > &g, int id)
{
	queue <int> q;
	q.push(id);
	vector <bool> used(g.size(), false);
	used[id] = true;
	while(!q.empty()) {
		int id = q.front();
		cout << (id + 1) << " ";
		q.pop();
		for(int i = 0; i < g[id].size(); ++i) {
			if(!used[g[id][i]]) {
				used[g[id][i]] = true;
				q.push(g[id][i]);
			}
		}
	}
	cout << endl;
}

int main()
{

	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	for(int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		--from;
		--to;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	bfs(g, 0);

	return 0;
}
