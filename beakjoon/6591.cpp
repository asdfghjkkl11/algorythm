#include <iostream>
#include <algorithm>
using namespace std;
long long n, k;
int main()
{
	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0)
			break;
		long long temp = 1;
		for (int i = 1; i <= min(n-k,k); i++) {
			temp *= (n - i + 1);
			temp /= i;
		}
		cout << temp << endl;
	}
	return 0;
}
