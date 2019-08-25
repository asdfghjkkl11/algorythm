#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[501][2] = { 0 }, cache[501][501] = { 0 };
int DP(int a, int b) {
	if (a == b)return 0;
	if (cache[a][b] != -1)
		return cache[a][b];
	int M = 987654321;
	for (int i = a; i < b; i++)
		M = min(M, DP(a, i) + DP(i + 1, b) + (arr[a][0] * arr[i][1] * arr[b][1]));
	return cache[a][b] = M;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cache[i][j] = -1;
	for (int i = 1; i < N; i++)
		cache[i - 1][i] = arr[i - 1][0] * arr[i][0] * arr[i][1];
	cout << DP(0, N - 1) << endl;
	return 0;
}
