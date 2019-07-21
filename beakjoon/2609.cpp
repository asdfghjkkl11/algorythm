#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int gcd(int a,int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main()
{
	cin >> n >> m;
	int g = gcd(max(n, m), min(n, m));
	cout << g << endl;
	cout << (n/ g)*m << endl;
	return 0;
}
