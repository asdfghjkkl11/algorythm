#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<pair<int, int>> v;
unordered_map<int, int> nine[3][3], garo[9], sero[9];
int mat[9][9];
void DFS(int T) {
	if (v.size() == T) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << mat[i][j] << ' ';
			cout << endl;
		}
		exit(0);
	}
	int i = v[T].first, j = v[T].second;
	for (int a = 1; a <= 9; a++) {
		if (nine[i / 3][j / 3][a] != 0 || garo[i][a] != 0 || sero[j][a] != 0)
			continue;
		nine[i / 3][j / 3][a]++;
		garo[i][a]++;
		sero[j][a]++;
		mat[i][j] = a;
		DFS(T+1);
		mat[i][j] = 0;
		sero[j][a]--;
		garo[i][a]--;
		nine[i / 3][j / 3][a]--;
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 0)
				v.push_back({ i,j });
			else {
				nine[i / 3][j / 3][mat[i][j]]++;
				garo[i][mat[i][j]]++;
				sero[j][mat[i][j]]++;
			}
		}
	}
	DFS(0);
	return 0;
}
