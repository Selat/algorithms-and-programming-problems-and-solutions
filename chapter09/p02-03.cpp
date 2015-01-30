#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 9.2.3. An undirected graph is called a bipartite graph if its vertices may be
 * colored in two colors in such a way that each edge connects vertices of different
 * colors. Find an algorithm that checks whether a graph is a bipartite graph in time
 * C · (number of edges + number of vertices).
 */


void bfs(const vector <vector <int> > &g, const vector <bool> &colors, int id)
{
	queue <pair <int, bool> > q;
	vector <bool> used(g.size(), false);
	bool biparate = true;
	q.push(make_pair(id, colors[id]));
	used[id] = true;
	while(!q.empty() && biparate) {
		int id = q.front().first;
		bool color = !q.front().second;
		q.pop();
		for(int i = 0; i < g[id].size(); ++i) {
			int to = g[id][i];
			if(colors[to] != color) {
				biparate = false;
				break;
			}
			if(!used[to]) {
				used[to] = true;
				q.push(make_pair(to, color));
			}
		}
	}
	if(biparate) {
		cout << "Biparate" << endl;
	} else {
		cout << "Not biparate" << endl;
	}
}

int main()
{

	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	vector <bool> color(n);
	for(int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		color[i] = (tmp == 1);
	}
	for(int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		--from;
		--to;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	bfs(g, color, 0);

	return 0;
}
