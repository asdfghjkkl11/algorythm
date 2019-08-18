#include <iostream>
using namespace std;
int cache[10][100][4], N;
long long DP(int a, int b, int c) {
	if (b == N) {
		long long result = 0;
		for (int i = 9; i > 0; i--) {
			c = (i == 9) ? 2 : 0;
			result += DP(i, b - 1, c);
			result %= 1000000000;
		}
		return result;
	}
	if (cache[a][b][c] != -1)
		return cache[a][b][c];
	if (b == 0)
		return (c == 3) ? 1 : 0;
	long long result = 0;
	if (a > 0) {
		int t = (a == 1) ? c | 1 : c;
		result += DP(a - 1, b - 1, t);
	}
	if (a < 9) {
		int t = (a == 8) ? c | 2 : c;
		result += DP(a + 1, b - 1, t);
	}
	return cache[a][b][c] = result % 1000000000;
}
int main() {
	cin >> N;
	for (int k = 0; k<10; k++)
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 4; j++)
				cache[k][i][j] = -1;
	cout << DP(0, N, 0) << endl;
	return 0;
}
