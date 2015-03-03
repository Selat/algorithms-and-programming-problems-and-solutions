#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

/*
 * 8.1.7. A finite set and a binary operation hu, vi 7→ u ◦ v defined on this set
 * are given (the operation may be noncommutative and nonassociative). We have n
 * elements a_1 , ..., a_n from the set and one more element x. Check if it is possible to
 * insert parentheses in the expression a_1 ◦ ... ◦ a_n in such a way that the result is equal
 * to x. The number of operations should not exceed Cn^3 for some constant C (which
 * depends on the cardinality of the set given).
 *
 * The solution just fills the table B of size n * n, where b[i][j] = {set of all possible values of
 * subexpression a_i * ... a_j for different placements of parentheses}
 */


const int MAXN = 100;
set <int> b[MAXN][MAXN];

int operation(int a, int b)
{
	return a - b;
}

bool solve(vector <int> &a, int x)
{
	stack <pair <int, int> > s;
	for(int i = 0; i < a.size() - 1; ++i) {
		b[i][i].insert(a[i]);
		b[i][i + 1].insert(operation(a[i], a[i + 1]));
	}
	b[a.size() - 1][a.size() - 1].insert(a[a.size() - 1]);
	s.push(make_pair(0, a.size() - 1));
	while(!s.empty()) {
		int l = s.top().first;
		int r = s.top().second;
		bool can_compute = true;
		for(int i = l; i < r; ++i) {
			if(b[l][i].empty()) {
				can_compute = false;
				s.push(make_pair(l, i));
			}
			if(b[i + 1][r].empty()) {
				can_compute = false;
				s.push(make_pair(i + 1, r));
			}
		}
		if(can_compute) {
			for(int i = l; i < r; ++i) {
				for(auto j : b[l][i]) {
					for(auto k : b[i + 1][r]) {
						b[l][r].insert(operation(j, k));
					}
				}
			}
			s.pop();
		}
	}

	return (b[0][a.size() - 1].find(x) != b[0][a.size() - 1].end());
}

int main()
{
	vector <int> a;
	int n, x;
	cin >> n >> x;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if(solve(a, x)) {
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}
	return 0;
}
