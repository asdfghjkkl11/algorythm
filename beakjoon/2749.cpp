#include <iostream>
using namespace std;
long long n;
int fib[1500000] = {0,1};
int main()
{
	cin >> n;
	n %= 1500000;
	if (n > 1)
		for (int i = 2; i <= n;i++)
			fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000;
	cout << fib[n] << endl;
	return 0;
}
