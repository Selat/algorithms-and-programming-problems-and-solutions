#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.16. The polynomial multiplication algorithm given above uses about n^2 op-
 * erations to compute the product of two polynomials of degree n. Find an (asymptot-
 * ically) more effective algorithm that uses only O(n^(log 4/ log 3) ) operations.
 */

class Polynomial;

istream& operator>>(istream &in, Polynomial &p);
ostream& operator<<(ostream &out, const Polynomial &p);

class Polynomial
{
public:
	Polynomial()
	{
	}
	Polynomial(int n) :
		m_data(n, 0)
	{
		for(int i = 0; i < n; ++i) {
			m_data[i] = 0;
		}
	}
	Polynomial(const Polynomial &p) :
		m_data(p.m_data)
	{
	}
	int &operator[](int i)
	{
		return m_data[i];
	}
	int operator[](int i) const
	{
		return m_data[i];
	}
	int size() const
	{
		return m_data.size();
	}
	void resize(int n)
	{
		m_data.resize(n);
	}

	Polynomial& operator=(const Polynomial &p)
	{
		if(size() != p.size()) {
			resize(p.size());
		}
		m_data = p.m_data;
	}
	Polynomial& operator+=(const Polynomial &p)
	{
		int n = min(size(), p.size());
		for(int i = 0; i < n; ++i) {
			m_data[i] += p[i];
		}
	}
	Polynomial& operator-=(const Polynomial &p)
	{
		int n = min(size(), p.size());
		for(int i = 0; i < n; ++i) {
			m_data[i] -= p[i];
		}
	}
	Polynomial operator+(const Polynomial &p)
	{
		Polynomial tmp(*this);
		tmp += p;
		return tmp;
	}

	Polynomial& operator*=(const Polynomial &p)
	{
		return *this = *this * p;
	}
	// Slow variant
	// Polynomial operator*(const Polynomial &b)
	// {
	// 	const Polynomial &a = *this;
	// 	Polynomial c(a.size() + b.size() - 1);
	// 	for(int i = 0; i < a.size(); ++i) {
	// 		for(int j = 0; j < b.size(); ++j) {
	// 			c[i + j] += a[i] * b[j];
	// 		}
	// 	}
	// 	return c;
	// }
	// Fast variant
	Polynomial operator*(const Polynomial &b)
	{
		const Polynomial &a = *this;
		if(a.size() == 1) {
			Polynomial res(1);
			res[0] = a[0] * b[0];
			return res;
		} else if (size() != b.size()) {
			int n = max(size(), b.size());
			Polynomial ta(n), tb(n);
			ta += a;
			tb += b;
			return ta * tb;
		} else {
			int n = a.size() - 1;
			int p = n / 2 + 1;
			Polynomial pa((n - 1) / 2 + 1);
			Polynomial pb(n / 2 + 1);
			Polynomial pc((n - 1)/ 2 + 1);
			Polynomial pd(n / 2 + 1);
			for(int i = 0; i < pa.size(); ++i) {
				pa[i] = m_data[i + p];
				pc[i] = b[i + p];
			}
			for(int i = 0; i < pb.size(); ++i) {
				pb[i] = m_data[i];
				pd[i] = b[i];
			}

			Polynomial ps1(max(pa.size(), pb.size()));
			Polynomial ps2(max(pc.size(), pd.size()));
			ps1 += pa;
			ps1 += pb;
			ps2 += pc;
			ps2 += pd;

			Polynomial pm3 = pa * pc;
			Polynomial pm1 = pb * pd;
			Polynomial pm2 = ps1 * ps2;
			pm2 -= pm1;
			pm2 -= pm3;

			Polynomial res(a.size() * 2 - 1);

			for(int i = 0; i < pm1.size(); ++i) {
				res[i] += pm1[i];
			}
			for(int i = 0; i < pm2.size(); ++i) {
				res[i + p] += pm2[i];
			}
			p = n / 2 * 2 + 2;
			for(int i = 0; i < pm3.size(); ++i) {
				res[i + p] += pm3[i];
			}
			return res;
		}
	}

private:
	vector <int> m_data;
};

istream& operator>>(istream &in, Polynomial &p)
{
	int n;
	in >> n;
	++n;
	p.resize(n);
	for(int i = 0; i < n; ++i) {
		in >> p[i];
	}
	return in;
}

ostream& operator<<(ostream &out, const Polynomial &p)
{
	for(int i = 0; i < p.size(); ++i) {
		out << p[i] << " ";
	}
	return out;
}

int main()
{
	Polynomial a, b;
	cin >> a >> b;
	cout << (a * b) << endl;
	return 0;
}
