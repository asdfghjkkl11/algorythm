#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, mat[20][20], dir[4][2] = { { -1,0 },{ 0,-1 },{ 0,1 },{ 1,0 } };
int res = 0, ret = 0, status = 2, fish[7] = { 0 }, feed = 2, remain = 0;
bool visit[20][20] = { 0 };
vector<int> v;
pair<int, int>shark;
struct cmp {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> clear() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>q;
	return q;
}
void bfs() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>que, temp;
	que.push(shark);
	visit[shark.first][shark.second] = true;
	while (!que.empty() && remain != 0) {
		temp = clear();
		int len = que.size();
		for (int i = 0; i < len; i++) {
			pair<int, int>p = que.top();
			que.pop();
			if (mat[p.first][p.second] < status&&mat[p.first][p.second] != 0) {
				mat[p.first][p.second] = 0;
				feed--;
				remain--;
				if (status < 7 && feed == 0) {
					remain += fish[status];
					feed = ++status;
				}
				temp = clear();
				temp.push(p);
				for (int j = 0; j < N; j++)
					for (int k = 0; k < N; k++)
						visit[j][k] = false;
				visit[p.first][p.second] = true;
				v.push_back(ret);
				ret = 0;
				break;
			}
			for (int j = 0; j < 4; j++) {
				int x = p.first + dir[j][0], y = p.second + dir[j][1];
				if (x >= 0 && x < N&&y >= 0 && y < N)
					if (mat[x][y] <= status && !visit[x][y]) {
						temp.push({ x,y });
						visit[x][y] = true;
					}
			}
		}
		ret++;
		que = temp;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 9) {
				shark = { i,j };
				mat[i][j] = 0;
			}
			else
				fish[mat[i][j]]++;
		}
	remain = fish[1];
	bfs();
	for (int i = 0; i < v.size(); i++)
		res += v[i]-1;
	if (!v.empty())
		res++;
	cout << res << endl;
	return 0;
}
