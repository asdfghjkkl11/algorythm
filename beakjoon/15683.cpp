#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, mat[8][8], result = 64, dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
vector<pair<int, int>>v;
void Ps(pair<int, int> p, int a) {
	int i = p.first + dir[a][0], j = p.second + dir[a][1];
	while (i >= 0 && i < N&&j >= 0 && j < M&&mat[i][j] % 10 != 6) {
		mat[i][j] += 10;
		i += dir[a][0];
		j += dir[a][1];
	}
}
void Ms(pair<int, int> p, int a) {
	int i = p.first + dir[a][0], j = p.second + dir[a][1];
	while (i >= 0 && i < N&&j >= 0 && j < M&&mat[i][j] % 10 != 6) {
		mat[i][j] -= 10;
		i += dir[a][0];
		j += dir[a][1];
	}
}
void BF(int a) {
	if (a == v.size()) {
		int ret = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (mat[i][j] == 0)
					ret++;
		result = min(result, ret);
		return;
	}
	pair<int, int>p = v[a];
	int index = mat[v[a].first][v[a].second]%10;
	if (index == 1) {
		for (int i = 0; i < 4; i++) {
			Ps(p, i);
			BF(a + 1);
			Ms(p, i);
		}
	}
	else if (index == 2) {
		for (int i = 0; i < 2; i++) {
			Ps(p, i);
			Ps(p, i+2);
			BF(a + 1);
			Ms(p, i);
			Ms(p, i+2);
		}
	}
	else if (index == 3) {
		for (int i = 0; i < 4; i++) {
			Ps(p, i);
			Ps(p, (i + 1)%4);
			BF(a + 1);
			Ms(p, i);
			Ms(p, (i + 1)%4);
		}
	}
	else if (index == 4) {
		for (int i = 0; i < 4; i++) {
			Ps(p, i);
			Ps(p, (i + 1) % 4);
			Ps(p, (i + 2) % 4);
			BF(a + 1);
			Ms(p, i);
			Ms(p, (i + 1) % 4);
			Ms(p, (i + 2) % 4);
		}
	}
	else if (index == 5) {
		Ps(p, 0);
		Ps(p, 1);
		Ps(p, 2);
		Ps(p, 3);
		BF(a + 1);
		Ms(p, 0);
		Ms(p, 1);
		Ms(p, 2);
		Ms(p, 3);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i<N; i++)
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
			if (mat[i][j] != 0 && mat[i][j] != 6)
				v.push_back({ i,j });
		}
	BF(0);
	cout << result << endl;
	return 0;
}
