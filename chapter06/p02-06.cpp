#include <iostream>
#include <vector>
#include <queue>

/*
 * 6.2.6. Suppose a directed graph satisfies two requirements: (1) it is connected;
 * that is, there is a path from any given vertex to any other vertex; and (2) for any vertex
 * the number of incoming edges is equal to the number of outgoing edges. Prove there
 * exists an edge cycle that traverses each edge exactly once. Give an algorithm to find
 * this cycle.
 */

using namespace std;

int n, m;
vector <vector <int> > g;
vector <int> used_id;

void buildPath(vector <int> &path)
{
	int not_used_num = n;
	queue <int> q;
	q.push(0);
	path.clear();
	path.push_back(0);
	while(not_used_num > 0) {
		int v = q.back();
		if(used_id[v] < g[v].size()) {
			path.push_back(g[v][used_id[v]]);
			q.push(g[v][used_id[v]++]);
			if(used_id[v] == g[v].size()) {
				--not_used_num;
			}
		} else {
			if(v != q.front()) {
				path.push_back(q.front());
			}
			q.push(q.front());
			q.pop();
		}
	}
}

int main()
{
	int from, to;
	vector <int> path;
	cin >> n >> m;
	g.resize(n);
	used_id.assign(n, 0);
	for(int i = 0; i < m; ++i) {
		cin >> from >> to;
		--from;
		--to;
		g[from].push_back(to);
	}

	buildPath(path);

	for(int i = 0; i < path.size(); ++i) {
		cout << path[i] + 1 << " ";
	}
	cout << endl;

	return 0;
}
