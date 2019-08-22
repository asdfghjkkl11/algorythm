#include <iostream>
using namespace std;
long n;
long fact(long a) {
	long temp = 1;
	for (int i = 0; i < a; i++) {
		temp *= (a - i);
		temp %= 1000000007;
	}
	return temp;
}
int main()
{
	cin >> n;
	long A;
	A = fact(n);
	cout << A << endl;
	return 0;
}
