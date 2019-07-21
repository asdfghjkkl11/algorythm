#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int metrix[25][25];
bool visited[25][25];
vector<int> answer;
int cnt;
int m;
void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	// Up
	if (x - 1 >= 0 && !visited[x - 1][y] && metrix[x - 1][y] == 1) {
		dfs(x - 1, y);
	}
	// Down
	if (x + 1 < m && !visited[x + 1][y] && metrix[x + 1][y] == 1) {
		dfs(x + 1, y);
	}
	// Left
	if (y - 1 >= 0 && !visited[x][y - 1] && metrix[x][y - 1] == 1) {
		dfs(x, y - 1);
	}
	// Right
	if (y + 1 < m && !visited[x][y + 1] && metrix[x][y + 1] == 1) {
		dfs(x, y + 1);
	}
}

int main()
{
	cin >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			if(t=='1')
				metrix[i][j] = 1;
			else
				metrix[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cnt = 0;
			if (!visited[i][j] && metrix[i][j] == 1) {
				dfs(i, j);
			}
			if (cnt >0)
				answer.push_back(cnt);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}
