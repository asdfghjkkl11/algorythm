#include <iostream>
using namespace std;
long long n, k;
long long fact(long long a) {
	long long temp = 1;
	for (int i = 0; i < a; i++) {
		temp *= (a - i);
		temp %= 1000000007;
	}
	return temp;
}
long long mul(long long a) {
	long long temp = 1;
	long long b = 1000000005;
	while (b > 0) {
		if (b % 2 != 0) {
			temp *= a;
			temp %= 1000000007;
		}
		a *= a;
		a %= 1000000007;
		b /= 2;
	}
	return temp;
}
int main()
{
	cin >> n >> k;
	long long A, B;
	A = fact(n);
	B = fact(k)*fact(n - k) % 1000000007;
	B = mul(B);
	B = (A*B) % 1000000007;
	cout << B << endl;
	return 0;
}
