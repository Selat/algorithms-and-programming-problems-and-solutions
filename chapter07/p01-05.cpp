#include <iostream>

using namespace std;

/*
 * 7.1.5. What happens if we replace the line
 *     power:= power(a*a, n div 2)
 * in the above program by the line
 *     power:= power(a, n div 2)* power(a, n div 2)
 */

double pow(double a, int n)
{
	if(n == 0) {
		return 1.0;
	} else if(n & 1) {
		return a * pow(a, n - 1);
	} else {
		double tmp = pow(a, n / 2);
		return tmp * tmp;
	}
}

int main()
{
	double a;
	int n;
	cin >> a >> n;
	cout << pow(a, n) << endl;
	return 0;
}
