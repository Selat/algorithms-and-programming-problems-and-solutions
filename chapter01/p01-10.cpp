#include <iostream>

using namespace std;

/*
 * 1.1.1. Consider two integer variables a and b. Write a program block that
 * exchanges the values of a and b (i.e., the value of a becomes the value
 * of b and vice versa).
 */

typedef unsigned long long ull;

template <typename T>
class Matrix
{
public:
	Matrix(int n, int m, T v) : m_n(n), m_m(m), m_data(nullptr)
	{
		m_data = new T[m_n * m_m];
		for(int i = 0; i < m_n; ++i) {
			for(int j = 0; j < m_m; ++j) {
				set(i, j, 0);
			}
		}
		if(m_n == m_m) {
			for(int i = 0; i < m_n; ++i) {
				set(i, i, v);
			}
		}
	}
	Matrix(int n, int m) : Matrix(n, m, 0)
	{
	}
	Matrix(const Matrix &m) : Matrix(m.m_n, m.m_m)
	{
		*this = m;
	}
	~Matrix()
	{
		delete[] m_data;
	}
	void set(int i, int j, T v)
	{
		m_data[m_n * i + j] = v;
	}
	T get(int i, int j) const
	{
		return m_data[m_n * i + j];
	}
	int getRows() const
	{
		return m_n;
	}
	int getColumns() const
	{
		return m_m;
	}
	Matrix<T> operator*(const Matrix<T> &m)
	{
		Matrix res(m_n, m.m_m, 0);
		for(int i = 0; i < m_n; ++i) {
			for(int j = 0; j < m.m_m; ++j) {
				for(int k = 0; k < m_m; ++k) {
					T tmp = get(i, k) * m.get(k, j) + res.get(i, j);
					res.set(i, j, tmp);
				}
			}
		}
		return res;
	}

	Matrix<T>& operator=(const Matrix<T> &m)
	{
		delete[] m_data;
		m_n = m.m_n;
		m_m = m.m_m;
		m_data = new T[m_n * m_m];
		for(int i = 0; i < m_n; ++i) {
			for(int j = 0; j < m_m; ++j) {
				set(i, j, m.get(i, j));
			}
		}
		return *this;
	}

private:
	int m_n, m_m;
	T *m_data;
};

template <typename T>
ostream& operator<<(ostream &out, const Matrix<T> &matrix)
{
	int n = matrix.getRows();
	int m = matrix.getColumns();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			out << matrix.get(i, j) << " ";
		}
		out << endl;
	}
	return out;
}

template <typename T>
Matrix<T> pow(Matrix<T> &a, int n)
{
	Matrix<T> res(a.getRows(), a.getColumns(), 1);
	while(n > 0) {
		if(n & 1) {
			res = res * a;
		}
		a = a * a;
		n >>= 1;
	}
	return res;
}

ull fib(int n)
{
	Matrix<ull> m(2, 2);
	m.set(0, 0, 1);
	m.set(0, 1, 1);
	m.set(1, 0, 1);
	m.set(1, 1, 0);
	Matrix<ull> f(1, 2);
	f.set(0, 1, 0);
	f.set(0, 1, 1);
	m = pow(m, n);
	f = f * m;
	return f.get(0, 0);
}

int main()
{
	int n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}
