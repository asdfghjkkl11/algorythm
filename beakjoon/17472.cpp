#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
int N, M, mat[10][10] = { 0 }, save[10][10] = { 0 }, dis[6][6] = { 0 }, dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
vector<vector<pair<int, int>>> v;
void bfs() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (mat[i][j] == 1) {
				queue<pair<int, int>>que;
				vector<pair<int, int>>tv;
				que.push({ i,j });
				while (!que.empty()) {
					pair<int, int>p = que.front();
					que.pop();
					if (mat[p.first][p.second] == 0)
						continue;
					mat[p.first][p.second] = 0;
					tv.push_back(p);
					for (int k = 0; k < 4; k++) {
						int x = p.first + dir[k][0], y = p.second + dir[k][1];
						if (x >= 0 && x < N&&y >= 0 && y < M)
							if (mat[x][y] == 1)
								que.push({ x, y });
					}
				}
				v.push_back(tv);
			}
}
int check(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		if (b.second > a.second) {
			for(int i= a.second + 1;i<b.second;i++)
				if (save[b.first][i] == 1)
					return 20;
			return (b.second - a.second - 1 < 2) ? 20 : b.second - a.second - 1;
		}
		for (int i = b.second + 1; i<a.second; i++)
			if (save[b.first][i] == 1)
				return 20;
		return (a.second - b.second - 1 < 2) ? 20 : a.second - b.second - 1;
	}
	if (a.second == b.second) {
		if (b.first > a.first) {
			for (int i = a.first + 1; i<b.first; i++)
				if (save[i][b.second] == 1)
					return 20;
			return (b.first - a.first - 1 < 2) ? 20 : b.first - a.first - 1;
		}
		for (int i = b.first + 1; i<a.first; i++)
			if (save[i][b.second] == 1)
			return 20;
		return (a.first - b.first - 1 < 2) ? 20 : a.first - b.first - 1;
	}
	return 20;
}
int distance(int a, int b) {
	int result = 20;
	for (int i = 0; i < v[a].size(); i++)
		for (int j = 0; j < v[b].size(); j++)
			result = min(result, check(v[a][i], v[b][j]));
	return (result == 20) ? 0 : result;
}
void make_bridge() {
	for (int i = 0; i < v.size() - 1; i++)
		for (int j = i + 1; j < v.size(); j++) {
			int d = distance(i, j);
			dis[i][j] = d;
			dis[j][i] = d;
		}
}
int prim() {
	bool visit[6] = { 0 };
	int dist[7] = { 0 }, index = 0, len = v.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++)
			if (dis[i][j] == 0)
				dis[i][j] = 20;
		dist[i] = 20;
	}
	dist[6] = 20;
	for (int i = 0; i < len - 1;i++) {
		visit[index] = true;
		int mi = 6;
		for (int j = 0; j < len; j++) {
			if (!visit[j]) {
				dist[j] = min(dist[j], dis[index][j]);
				if (dist[j] < dist[mi])
					mi = j;
			}
		}
		if (mi == 6)
			return -1;
		index = mi;
	}
	int result = 0;
	for (int i = 0; i < len; i++)
		result += (dist[i] == 20) ? 0 : dist[i];
	return result;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
			save[i][j] = mat[i][j];
		}
	bfs();
	make_bridge();
	cout << prim() << endl;
	return 0;
}
