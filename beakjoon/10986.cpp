#include <iostream>
using namespace std;
int n, m, a;
int sum[1000000] = { 0 };
long long check[1000] = { 0 };
long long C = 0;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum[i] = a %= m;
		if (i != 0)
			sum[i] += sum[i - 1] % m;
		sum[i] %= m;
		check[sum[i]]++;
	}
	C += check[0];
	for (int i = 0; i < m; i++) {
		C += check[i] * (check[i] - 1) / 2;
	}
	cout << C << endl;
	return 0;
}
