#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[10004] = { 0 };
int dps[10004] = { 0 };
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dp[i];
	dps[1] = dp[1];
	dps[2] = dp[1] + dp[2];
	for (int i = 3; i <= n; i++)
		dps[i] = max({ dps[i - 1], dps[i - 2] + dp[i], dps[i - 3] + dp[i - 1] + dp[i] });
	cout << dps[n] << endl;
	return 0;
}
