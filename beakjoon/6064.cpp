#include <iostream>
#include <string.h>
using namespace std;
int gcd(int a,int b) {
	int x = a, y = b;
	if (b>a) {
		int t = a;
		a = b;
		b = t;
	}
	while (true) {
		int g = a%b;
		if (g == 0)
			break;
		a = b;
		b = g;
	}
	return x*y / b;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t;i++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int g = gcd(m,n);
		int j = 0,k = 0;
		while (true) {
			int a, b;
			a = (j*m) + x;
			b = (k*n) + y;
			if (a == b) {
				cout << a << "\n";
				break;
			}
			if (a > g || b > g) {
				cout << -1 << "\n";
				break;
			}
			if (a < b)
				j++;
			else
				k++;
		}
	}
}
