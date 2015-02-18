#include <iostream>
#include <vector>

/*
 * 6.2.9. The same problem for deques.
 */

using namespace std;

template <typename T>
class Dequeue
{
public:
	Dequeue(int n, int k);
	void push_front(int id, const T &val);
	void push_back(int id, const T &val);
	void pop_front(int id);
	void pop_back(int id);
	T front(int id);
	T back(int id);
	bool empty(int id);
private:
	int getFreeCell();
	void returnFreeCell(int id);

	vector <int> m_first;
	vector <int> m_last;
	vector <int> m_next;
	vector <int> m_prev;
	vector <T> m_data;
	int m_free_id;
};

template <typename T>
Dequeue<T>::Dequeue(int n, int k) :
	m_data(n),
	m_next(n),
	m_prev(n),
	m_first(k),
	m_last(k),
	m_free_id(0)
{
	for(int i = 0; i < n - 1; ++i) {
		m_next[i] = i + 1;
	}
	m_next[n - 1] = 0;
	for(int i = 1; i < n; ++i) {
		m_prev[i] = i - 1;
	}
	m_prev[0] = n - 1;
	for(int i = 0; i < k; ++i) {
		m_first[i] = -1;
		m_last[i] = -1;
	}
}

template <typename T>
void Dequeue<T>::push_front(int id, const T &val)
{
	int cell_id = getFreeCell();
	m_data[cell_id] = val;
	if(m_first[id] == -1) {
		m_last[id] = m_first[id] = cell_id;
		m_prev[cell_id] = cell_id;
	} else {
		m_prev[cell_id] = m_prev[m_first[id]];
	}
	m_prev[m_first[id]] = cell_id;
	m_next[m_last[id]] = cell_id;
	m_next[cell_id] = m_first[id];
	m_first[id] = cell_id;
}

template <typename T>
void Dequeue<T>::push_back(int id, const T &val)
{
	int cell_id = getFreeCell();
	m_data[cell_id] = val;
	if(m_last[id] == -1) {
		m_first[id] = m_last[id] = cell_id;
		m_next[cell_id] = cell_id;
	} else {
		m_next[cell_id] = m_next[m_last[id]];
	}
	m_prev[m_first[id]] = cell_id;
	m_next[m_last[id]] = cell_id;
	m_prev[cell_id] = m_last[id];
	m_last[id] = cell_id;
}

template <typename T>
void Dequeue<T>::pop_front(int id)
{
	int cell_id = m_first[id];
	m_first[id] = m_next[cell_id];
	m_prev[m_first[id]] = m_prev[cell_id];
	returnFreeCell(cell_id);
}

template <typename T>
void Dequeue<T>::pop_back(int id)
{
	int cell_id = m_last[id];
	m_last[id] = m_prev[cell_id];
	m_next[m_last[id]] = m_next[cell_id];
	returnFreeCell(cell_id);
}

template <typename T>
T Dequeue<T>::front(int id)
{
	return m_data[m_first[id]];
}

template <typename T>
T Dequeue<T>::back(int id)
{
	return m_data[m_last[id]];
}

template <typename T>
bool Dequeue<T>::empty(int id)
{
	return (m_first[id] == -1);
}

template <typename T>
int Dequeue<T>::getFreeCell()
{
	int cell_id = m_free_id;
	m_free_id = m_next[m_free_id];
	m_prev[m_free_id] = m_prev[cell_id];
	m_prev[cell_id] = -1;
	m_next[cell_id] = -1;
	return cell_id;
}

template <typename T>
void Dequeue<T>::returnFreeCell(int id)
{
	m_next[id] = m_free_id;
	m_prev[id] = m_prev[m_free_id];
	m_prev[m_free_id] = id;
	m_free_id = id;
}

int main()
{
	Dequeue<int> q(1000, 10);
	for(int k = 0; k < 6; ++k) {
		for(int i = 0; i < 100; ++i) {
			q.push_back(k, i);
		}
	}
	for(int k = 0; k < 6; ++k) {
		for(int i = 0; i < 100; ++i) {
			if(q.front(k) != i) {
				cout << "Error: " << k << " " << i << endl;
				return -1;
			}
			q.pop_front(k);
		}
	}
	return 0;
}
