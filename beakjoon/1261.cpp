#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, mat[100][100], dist[100][100];
char c;
pair<int, int> dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
struct cmp {
	bool operator()(pair<int,int> a, pair<int, int> b) {
		return dist[a.first][a.second] > dist[b.first][b.second];
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			cin >> c;
			mat[i][j]=c-'0';
			dist[i][j] = 100000;
		}
	dist[0][0] = 0;
	priority_queue< pair<int, int>, vector<pair<int,int>>, cmp> pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		pair<int, int>top= pq.top();
		for (int i = 0; i < 4; i++) {
			int dx=top.first+dir[i].first, dy = top.second + dir[i].second;
			if ((dx >= 0 && dx < M) && (dy >= 0 && dy < N))
				if (dist[dx][dy] > dist[top.first][top.second] + mat[dx][dy]) {
					dist[dx][dy] = dist[top.first][top.second] + mat[dx][dy];
					pq.push(make_pair(dx, dy));
				}
		}
		pq.pop();
	}
	cout << dist[M - 1][N - 1] << '\n';
	return 0;
}
