#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, result = 0;
vector<vector<int>> convert(int a, vector<vector<int>>&V) {
	vector<vector<int>>v = V;
	switch (a) {
	case 0:
		break;
	case 1:
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N / 2; j++)
				swap(v[i][j], v[i][N - 1 - j]);
		break;
	case 2:
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				swap(v[i][j], v[j][i]);
		break;
	case 3:
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				v[i][j] = V[N - 1 - j][i];
		break;
	}
	return v;
}
void dfs(int a, vector<vector<int>>&V) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			result = max(result, V[i][j]);
	if (a == 5)
		return;
	for (int i = 0; i < 4; i++) {
		vector<vector<int>>v = convert(i, V);
		for (int j = 0; j < N; j++) {
			int temp = -1;
			vector<int>t;
			for (int k = N - 1; k >= 0; k--) {
				if (v[j][k] != 0) {
					if (temp == -1)
						temp = v[j][k];
					else if (temp == v[j][k]) {
						t.push_back(temp * 2);
						temp = -1;
					}
					else {
						t.push_back(temp);
						temp = v[j][k];
					}
				}
			}
			if (temp != -1)
				t.push_back(temp);
			while (t.size() < N)
				t.push_back(0);
			for (int k = 0; k < N; k++)
				v[j][k] = t[N - 1 - k];
		}
		dfs(a + 1, v);
	}
}
int main() {
	cin >> N;
	vector<vector<int>>V(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> V[i][j];
	dfs(0, V);
	cout << result << endl;
	return 0;
}
