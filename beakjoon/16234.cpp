#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N, R, L, mat[50][50], result = 0, dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
bool visit[50][50];
int bfs() {
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = true;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (visit[i][j]) {
				queue<pair<int, int>>que;
				vector<pair<int, int>>v;
				que.push({ i,j });
				v.push_back({ i,j });
				visit[i][j] = false;
				while (!que.empty()) {
					pair<int, int>p = que.front();
					que.pop();
					for (int k = 0; k < 4; k++) {
						int x = p.first + dir[k][0], y = p.second + dir[k][1];
						if (x >= 0 && x < N&&y >= 0 && y < N)
							if (visit[x][y] && abs(mat[x][y] - mat[p.first][p.second]) >= L&&abs(mat[x][y] - mat[p.first][p.second]) <= R) {
								que.push({ x,y });
								visit[x][y] = false;
								v.push_back({ x,y });
							}
					}
				}
				if (v.size() != 1) {
					int people = 0;
					for (pair<int, int> p : v)
						people += mat[p.first][p.second];
					people /= v.size();
					for (pair<int, int> p : v)
						mat[p.first][p.second] = people;
					ret++;
				}
			}
		}
	return ret;
}
int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> mat[i][j];
	while (bfs() != 0) {
		result++;
	}
	cout << result << endl;
	return 0;
}
