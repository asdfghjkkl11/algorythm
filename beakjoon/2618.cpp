#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M, cache[1002][1002], arr[1002][2], route[1002];
int distance(int a, int b) {
	return abs(arr[a][0] - arr[b][0]) + abs(arr[a][1] - arr[b][1]);
}
int DP(int a, int b, int c) {
	if (cache[a][b] != -1)
		return cache[a][b];
	if (c == M + 2)
		return 0;
	return cache[a][b] = min(DP(c, b, c + 1) + distance(a, c), DP(a, c, c + 1) + distance(b, c));
}
void path(int a, int b, int c) {
	if (c == M + 2)
		return;
	int l = DP(c, b, c + 1) + distance(a, c), r = DP(a, c, c + 1) + distance(b, c);
	if (l < r) {
		route[c] = 1;
		path(c, b, c + 1);
	}
	else {
		route[c] = 2;
		path(a, c, c + 1);
	}
}
int main() {
	cin >> N >> M;
	arr[0][0] = 1, arr[0][1] = 1, arr[1][0] = N, arr[1][1] = N;
	for (int i = 2; i <= M + 1; i++)
		cin >> arr[i][0] >> arr[i][1];
	for (int i = 0; i <= M + 1; i++)
		for (int j = 0; j <= M + 1; j++)
			cache[i][j] = -1;
	cout << DP(0, 1, 2) << endl;
	path(0, 1, 2);
	for (int i = 0; i < M; i++)
		cout << route[i + 2] << endl;
	return 0;
}
