#include <iostream>
#include <algorithm>
using namespace std;
long long int n, m;
long long int gcd(long long int a, long long int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main()
{
	cin >> n >> m;
	long long int g = gcd(max(n, m), min(n, m));
	cout << (n/ g)*m << endl;
	return 0;
}
