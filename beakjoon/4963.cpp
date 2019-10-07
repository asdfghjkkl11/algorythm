#include <iostream>
#include <queue>
using namespace std;
int N, M, mat[50][50], dir[8][2] = { { 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 },{ -1,0 },{ -1,1 },{ 0,1 } };
int bfs() {
	int result = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (mat[i][j] == 1) {
				result++;
				queue<pair<int, int>>que;
				que.push({ i,j });
				mat[i][j] = 0;
				while (!que.empty()) {
					pair<int, int>p = que.front();
					que.pop();
					for (int i = 0; i < 8; i++) {
						int x = p.first + dir[i][0], y = p.second + dir[i][1];
						if (x >= 0 && x < M&&y >= 0 && y < N)
							if (mat[x][y] == 1) {
								que.push({ x,y });
								mat[x][y] = 0;
							}
					}
				}
			}
	return result;
}
int main() {
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			return 0;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				cin >> mat[i][j];
		cout << bfs() << endl;
	}
	return 0;
}
