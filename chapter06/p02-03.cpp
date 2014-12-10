#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Deque
{
public:
	Deque(int size) :
		m_data(size),
		m_first(0),
		m_last(0),
		m_border_transfer(false)
	{
	}
	void push_front(const T &t)
	{
		--m_first;
		if(m_first == -1) {
			m_first = m_data.size() - 1;
			m_border_transfer = true;
		}
		m_data[m_first] = t;
		++m_size;
	}
	void push_back(const T &t)
	{
		m_data[m_last++] = t;
		if(m_last == m_data.size()) {
			m_last = 0;
			m_border_transfer = false;
		}
		++m_size;
	}
	const T& front()
	{
		return m_data[m_first];
	}
	const T& back()
	{
		if(m_last == 0) {
			return m_data[m_data.size() - 1];
		} else {
			return m_data[m_last - 1];
		}
	}
	void pop_front()
	{
		++m_first;
		if(m_first == m_data.size()) {
			m_first = 0;
			m_border_transfer = false;
		}
		--m_size;
	}
	void pop_back()
	{
		--m_last;
		if(m_last == -1) {
			m_last = m_data.size() - 1;
			m_border_transfer = false;
		}
		--m_size;
	}
	bool empty()
	{
		return (m_size == 0);
	}
private:
	int m_first;
	int m_last;
	int m_size;
	// true => second element in the queue is to the left of the first one.
	// false => second element in the queue is to the right of the first one.
	// Example:
	// _ _ 1 2 3 4 _ _ _ -- false
	// 2 1 _ _ _ _ _ 4 3 -- true
	bool m_border_transfer;
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
	Deque<int> q(n);
	for(int i = 0; i < n; ++i) {
		q.push_front(a[i]);
	}
	for(int i = 0; i < n; ++i) {
		cout << q.front() << " ";
		q.pop_front();
	}
	cout << endl;
	return 0;
}
