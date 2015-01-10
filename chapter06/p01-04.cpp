#include <iostream>
#include <vector>

using namespace std;

/*
 * 6.1.4. Implement k stacks of elements of type T with a total of at most n ele-
 * ments using arrays with total length C(n + k). Each stack operation (except initial-
 * ization, which makes all stacks empty) should be performed in constant time (not
 * depending on n and k). (In other words, the implementation should require space
 * O(n + k) and run in time O(1) for each operation.)
 */

template <typename T>
class DoubleStack
{
public:
	DoubleStack(int size, int k) :
		m_a(size),
		m_next(size),
		m_top(k, -1),
		m_free(0)
	{
		for(int i = 0; i < size - 1; ++i) {
			m_next[i] = i + 1;
		}
		m_next[size - 1] = -1;
	}
	void push(int id, const T &data)
	{
		int cell = m_free;
		m_free = m_next[m_free];
		m_a[cell] = data;
		m_next[cell] = m_top[id];
		m_top[id] = cell;
	}
	void pop(int id)
	{
		int tmp = m_top[id];
		m_top[id] = m_next[m_top[id]];
		m_next[tmp] = m_free;
		m_free = tmp;
	}
	const T& top(int id)
	{
		return m_a[m_top[id]];
	}
	bool empty(int id)
	{
		return (m_top[id] == -1);
	}
private:
	vector <T> m_a;
	vector <int> m_next;
	vector <int> m_top;
	int m_free;
};

int main()
{
	int n, m;
	cin >> n >> m;
	DoubleStack <int> s(n + m, 2);
	for(int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		s.push(0, t);
	}
	for(int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		s.push(1, t);
	}

	while(!s.empty(0)) {
		cout << s.top(0) << " ";
		s.pop(0);
	}
	cout << endl;
	while(!s.empty(1)) {
		cout << s.top(1) << " ";
		s.pop(1);
	}
	cout << endl;
	return 0;
}
