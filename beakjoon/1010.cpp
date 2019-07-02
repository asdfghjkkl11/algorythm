#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, M;
long long cache[31][31];
long long DP(int n, int m) {
	if (cache[n][m] != -1)
		return cache[n][m];
	if (n == 0 || m == 0)
		return (n == 0) ? 1 : 0;
	long long result = 0;
	for (int i = 1; i <= m; i++)
		result += DP(n - 1, m - i);
	return cache[n][m] = result;
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		for (int j = 0; j <= N; j++)
			for (int k = 0; k <= M; k++)
				cache[j][k] = -1;
		long long result = DP(N, M);
		cout << result << endl;
	}
	return 0;
}
