#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
int book[501];
int cathe[501][501],dp[501][501];
int sum[501];
int main()
{
	for (cin >> t; t--;) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			book[j] = a;
			sum[j+1] = sum[j]+a;
			dp[j][j + 1] = 0;
			cathe[j][j + 1] = j+1;
		}
		for (int d = 2; d <= n; d++) {
			for (int i = 0; i + d <= n; i++) {
				int j = i + d;
				dp[i][j] = 2e9;
				for (int k = cathe[i][j - 1]; k <= cathe[i + 1][j]; k++) {
					int v = dp[i][k] + dp[k][j] + sum[j] - sum[i];
					if (dp[i][j] > v)
						dp[i][j] = v, cathe[i][j] = k;
				}
			}
		}
		cout << dp[0][n] << endl;
	}
	return 0;
}
