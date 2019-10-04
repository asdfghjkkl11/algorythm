#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
int N, M, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }, result = 0;;
char mat[20][20];
bool visit[20][20] = {0}, arr[26] = { 0 };
void dfs(int a,int b,int c) {
	result = max(result,c);
	visit[a][b] = !visit[a][b];
	arr[mat[a][b] - 'A'] = !arr[mat[a][b] - 'A'];
	for (int i = 0; i < 4;i++) {
		int x = a + dir[i][0], y = b + dir[i][1];
		if (x >= 0 && x < N&&y >= 0 && y < M)
			if (!visit[x][y]&& !arr[mat[x][y] - 'A'])
				dfs(x,y,c+1);
	}
	arr[mat[a][b] - 'A'] = !arr[mat[a][b] - 'A'];
	visit[a][b] = !visit[a][b];
}
int main() {
	cin >> N >> M;
	unordered_map<char, int>um;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> mat[i][j];
	dfs(0, 0, 1);
	cout << result << endl;
	return 0;
}
