#include <iostream>
#include <algorithm>
using namespace std;
int n, m, t;
int gcd(int a,int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main()
{
	for (cin >> t; t--;) {
		cin >> n >> m;
		int g = gcd(max(n,m),min(n,m));
		cout << n*m / g << endl;
	}
	return 0;
}
