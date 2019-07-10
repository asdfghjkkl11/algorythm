#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int mat[500][500];
int cathe[500][500];
int DP(int a, int b) {
	if (a == n - 1 && b == m - 1)
		return 1;
	if (cathe[a][b] != -1)
		return cathe[a][b];
	int sum = 0;
	if (a - 1 >= 0 && mat[a - 1][b]<mat[a][b])
		sum += DP(a - 1, b);
	if (b - 1 >= 0 && mat[a][b - 1]<mat[a][b])
		sum += DP(a, b - 1);
	if (a + 1 < n&&mat[a + 1][b]<mat[a][b])
		sum += DP(a + 1, b);
	if (b + 1 >= 0 && mat[a][b + 1]<mat[a][b])
		sum += DP(a, b + 1);
	return cathe[a][b] = sum;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			mat[i][j] = a;
			cathe[i][j] = -1;
		}
	}
	int result = DP(0, 0);
	cout << result << endl;
	return 0;
}
