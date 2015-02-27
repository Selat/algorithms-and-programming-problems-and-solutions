#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/*
 * 6.4.2. A priority queue does not employ First In First Out (FIFO) rule; only
 * an element’s priority is important. An element is added to the priority queue with
 * some priority (which is assumed to be an integer). When an element is taken from
 * the queue, it is the element with the greatest priority (or one of the elements with
 * greatest priority). Implement a priority queue in such a way that adding and removing
 * elements requires logarithmic (in the size of the queue) time.
 */

class Heap
{
public:
	Heap(int n);
	void push(int val);
	int min();
	void pop();
	void print()
	{
		for(int i = 1; i <= size_; ++i) {
			cout << data_[i] << " ";
		}
		cout << endl;
	}
private:
	void checkup(int id);
	void checkdown(int id);

	vector <int> data_;
	int size_;
};

Heap::Heap(int n) :
	data_(n + 1),
	size_(0)
{

}

void Heap::push(int val)
{
	data_[++size_] = val;
	checkup(size_);
}

int Heap::min()
{
	if(size_ == 0) {
		return INT_MAX;
	} else {
		return data_[1];
	}
}

void Heap::pop()
{
	if(size_ > 0) {
		data_[1] = data_[size_--];
		checkdown(1);
	}
}

void Heap::checkup(int id)
{
	int p = id / 2;
	if(p == 0) return;
	while((p != 0) && (data_[p] > data_[id])) {
		swap(data_[p], data_[id]);
		id = p;
		p = id / 2;
	}
}

void Heap::checkdown(int id)
{
	int c = 2 * id;
	if(c > size_) return;
	if((c + 1 <= size_) && (data_[c + 1] < data_[c])) c++;

	if(data_[c] < data_[id]) {
		swap(data_[c], data_[id]);
		checkdown(c);
	}
}

int main()
{
	int n, tmp;
	cin >> n;
	Heap h(n);
	for(int i = 0; i < n; ++i) {
		cin >> tmp;
		h.push(tmp);
	}

	for(int i = 0; i < n; ++i) {
		cout << h.min() << endl;
		h.pop();
	}
	return 0;
}
