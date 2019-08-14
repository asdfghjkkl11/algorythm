#include <iostream>
using namespace std;
int t, n, m;
int gcd(int a,int b) {
	return (b == 0)?a:gcd(b,a%b);
}
int main()
{
	for (cin >> t; t--;) {
		cin >> n >> m;
		int s = 1, r = 2;
		while (n != 1) {
			int a1 = s, b1 = r;
			int a2 = n, b2 = m;
			a1 *= b2;
			a2 *= b1;
			if (a2 > a1) {
				n = a2 - a1;
				m *= r;
				int g = gcd(m, n);
				n /= g;
				m /= g;
				r = m / n;
				if (m%n != 0)
					r++;
			}
			else
				r++;
		}
		cout << m << endl;
	}
	return 0;
}
