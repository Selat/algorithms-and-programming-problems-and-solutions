
#include <iostream>
#include <stack>

using namespace std;

/*
 * 6.2.2. (Communicated by A.G. Kushnirenko) Implement a queue using two
 * stacks (and a fixed number of variables of type T). For n queue operations starting
 * with an empty queue, the implementation should perform not more than Cn stack
 * operations.
 */

template <typename T>
class Queue
{
public:
	Queue();
	void push(const T &t);
	bool empty();
	const T& back();
	void pop();
private:
	void transferElements();

	stack <T> m_s1, m_s2;
};

template <typename T>
Queue<T>::Queue()
{
}

template <typename T>
void Queue<T>::push(const T &t)
{
	m_s1.push(t);
}

template <typename T>
bool Queue<T>::empty()
{
	return ((m_s1.size() == 0) && (m_s2.size() == 0));
}

template <typename T>
const T& Queue<T>::back()
{
	transferElements();
	return m_s2.top();
}

template <typename T>
void Queue<T>::pop()
{
	transferElements();
	m_s2.pop();
}

template <typename T>
void Queue<T>::transferElements()
{
	if(m_s2.empty()) {
		// Move all elements from the first stack to the second one.
		// The order of elements is reversed.
		while(!m_s1.empty()) {
			m_s2.push(m_s1.top());
			m_s1.pop();
		}
	}
}


int main()
{
	int n, tmp;
	Queue<int> q;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> tmp;
		q.push(tmp);
	}
	for(int i = 0; i < n; ++i) {
		cout << q.back() << " ";
		q.pop();
	}
};
