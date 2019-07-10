#include <iostream>
#include <algorithm>
using namespace std;
long long int n, m;
long long int gcd(long long int a, long long int b) {
	return (b == 0) ? a : gcd(b, a%b);
}
int main()
{
	cin >> n >> m;
	long long int g = gcd(max(n, m), min(n, m));
	for (int i = 0; i < g;i++)
		cout << 1;
	cout << endl;
	return 0;
}
