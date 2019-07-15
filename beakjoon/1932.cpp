#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> tri[500];
int dp[500];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++) {
			int a;
			cin >> a;
			tri[i].push_back(a);
		}
	for (int i = 0; i < n; i++)
		dp[i] = tri[n - 1][i];
	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j <= i;j++)
			dp[j] = tri[i][j] + max(dp[j], dp[j + 1]);
	cout << dp[0] << endl;
	return 0;
}
