#include <iostream>
#include <vector>

/*
 * 6.2.8. Implement k queues with total length not exceeding n, using memory of
 * size O(n + k) (that is, not exceeding C(n + k) for some constant C). Each operation
 * (except for initialization, which makes all the queues empty) should run in time O(1)
 * (that is, limited by a constant that does not depend on n).
 */

using namespace std;

template <typename T>
class Queue
{
public:
	Queue(int n, int k);
	void push(int id, const T &val);
	void pop(int id);
	T front(int id);
	T back(int id);
	bool empty(int id);
private:
	vector <int> m_first;
	vector <int> m_last;
	vector <int> m_next;
	vector <T> m_data;
	int m_free_id;
};

template <typename T>
Queue<T>::Queue(int n, int k) :
	m_data(n),
	m_next(n),
	m_first(k),
	m_last(k),
	m_free_id(0)
{
	for(int i = 0; i < n - 1; ++i) {
		m_next[i] = i + 1;
	}
	m_next[n - 1] = -1;
	for(int i = 0; i < k; ++i) {
		m_first[i] = -1;
		m_last[i] = -1;
	}
}

template <typename T>
void Queue<T>::push(int id, const T &val)
{
	if(m_first[id] == -1) {
		m_first[id] = m_free_id;
	} else {
		m_next[m_last[id]] = m_free_id;
	}
	int cell_id = m_free_id;
	m_data[cell_id] = val;
	m_last[id] = cell_id;
	m_free_id = m_next[m_free_id];
	m_next[cell_id] = -1;
}

template <typename T>
void Queue<T>::pop(int id)
{
	int cell_id = m_first[id];
	m_first[id] = m_next[cell_id];
	m_next[cell_id] = m_free_id;
	m_free_id = cell_id;
}

template <typename T>
T Queue<T>::front(int id)
{
	return m_data[m_first[id]];
}

template <typename T>
T Queue<T>::back(int id)
{
	return m_data[m_last[id]];
}

template <typename T>
bool Queue<T>::empty(int id)
{
	return (m_first[id] == -1);
}

int main()
{
	Queue<int> q(1000, 10);
	for(int k = 0; k < 10; ++k) {
		for(int i = 0; i < 100; ++i) {
			q.push(k, i);
		}
	}
	for(int k = 0; k < 10; ++k) {
		for(int i = 0; i < 100; ++i) {
			if(q.front(k) != i) {
				cout << "Error: " << k << " " << i << endl;
				return -1;
			}
			q.pop(k);
		}
	}
	return 0;
}
