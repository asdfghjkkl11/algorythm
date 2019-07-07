#include <iostream>
using namespace std;
int T, N, M, K, a, b;
int mat[51][51] = { 0 };
bool visit[51][51] = { 0 };
pair<int, int> dir[4] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
void find(int a, int b) {
	visit[a][b] = true;
	for (int i = 0; i < 4; i++) {
		int x = dir[i].first + a, y = dir[i].second + b;
		if ((x >= 0 && x < N) && (y >= 0 && y < M))
			if ((!visit[x][y]) && mat[x][y] == 1)
				find(x, y);
	}
}
int BFS() {
	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if ((!visit[i][j]) && mat[i][j] == 1) {
				find(i, j);
				result++;
			}
			visit[i][j] = true;
		}
	return result;
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M >> K;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				visit[j][k] = false;
				mat[j][k] = 0;
			}
		for (int j = 0; j < K; j++) {
			cin >> a >> b;
			mat[a][b] = 1;
		}
		int result = BFS();
		cout << result << endl;
	}
	return 0;
}
