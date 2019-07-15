#include <iostream>
using namespace std;
int metrix[100][100];
long route[100][100];
int m;
long DFS(int a, int b) {
	if (route[a][b] != -1)
		return route[a][b];
	if (metrix[a][b] == 0)
		if (a == m - 1 && b == m - 1)
			return 1;
		else
			return 0;
	long dfs = 0;
	if (b + metrix[a][b] < m)
		dfs += DFS(a, b + metrix[a][b]);
	if (a + metrix[a][b] < m)
		dfs += DFS(a + metrix[a][b], b);
	return route[a][b] = dfs;
}
int main()
{
	cin >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			metrix[i][j] = a;
			route[i][j] = -1;
		}
	long answer = 0;
	answer = DFS(0, 0);
	cout << answer << '\n';
}
