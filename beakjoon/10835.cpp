#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, cache[2000][2000];
vector<int>L, R;
int dp(int a, int b) {
	if (a == N || b == N)
		return 0;
	if (cache[a][b] != -1)
		return cache[a][b];
	if (L[a] > R[b])
		return cache[a][b] = R[b] + dp(a, b + 1);
	return cache[a][b] = max(dp(a + 1, b), dp(a + 1, b + 1));
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cache[i][j] = -1;
	for (int i = 0; i < N; i++) {
		cin >> M;
		L.push_back(M);
	}
	for (int i = 0; i < N; i++) {
		cin >> M;
		R.push_back(M);
	}
	cout << dp(0, 0) << endl;
	return 0;
}
