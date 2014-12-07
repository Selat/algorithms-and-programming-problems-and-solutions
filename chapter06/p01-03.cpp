#include <iostream>
#include <vector>

using namespace std;

/*
 * 6.1.3. Implement two stacks using one array. The total number of elements in
 * both stacks is limited by the array length; all stack operations should run in O(1)
 * time (i.e., running time should be bounded by a constant).
 */

template <typename T>
class DoubleStack
{
public:
	DoubleStack(int size) :
		m_a(size),
		m_id1(0),
		m_id2(size - 1)
	{
	}
	void push1(const T &data)
	{
		m_a[m_id1++] = data;
	}
	void push2(const T &data)
	{
		m_a[m_id2--] = data;
	}
	void pop1()
	{
		--m_id1;
	}
	void pop2()
	{
		++m_id2;
	}
	const T& top1()
	{
		return m_a[m_id1 - 1];
	}
	const T& top2()
	{
		return m_a[m_id2 + 1];
	}
	bool empty1()
	{
		return (m_id1 == 0);
	}
	bool empty2()
	{
		return (m_id2 == m_a.size() - 1);
	}
private:
	int m_id1, m_id2;
	vector <T> m_a;
};

int main()
{
	int n, m;
	cin >> n >> m;
	DoubleStack <int> s(n + m);
	for(int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		s.push1(t);
	}
	for(int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		s.push2(t);
	}

	while(!s.empty1()) {
		cout << s.top1() << " ";
		s.pop1();
	}
	cout << endl;
	while(!s.empty2()) {
		cout << s.top2() << " ";
		s.pop2();
	}
	cout << endl;
	return 0;
}
