#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Queue
{
public:
	Queue(int size) :
		m_data(size),
		m_first(0),
		m_last(0)
	{
	}
	void push(const T &t)
	{
		++m_size;
		m_data[m_last++] = t;
		if(m_last == m_data.size()) {
			m_last = 0;
		}
	}
	bool empty()
	{
		return (m_size == 0);
	}
	const T& back()
	{
		return m_data[m_first];
	}
	void pop()
	{
		++m_first;
		if(m_first == m_data.size()) {
			m_first = 0;
		}
	}
private:
	int m_first;
	int m_last;
	int m_size;
	vector <T> m_data;
};

int main()
{
	int n;
	vector <int> a;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	Queue<int> q(n);
	for(int i = 0; i < n; ++i) {
		for(int i = 0; i < n; ++i) {
			q.push(a[i]);
		}
		for(int i = 0; i < n; ++i) {
			q.pop();
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << q.back() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}
