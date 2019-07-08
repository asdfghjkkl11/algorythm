#include <iostream>
#include <queue>
using namespace std;
int matrix[1001][1001] = {0};
bool visit[1001] = {false};
int n, m, v;
queue<int> stack;
void DFS(int a) {
	if (visit[a] == true)
		return;
	cout << a << ' ';
	visit[a] = true;
	for (int i = 0; i <= n;i++)
		if (matrix[a][i] == 1)
			DFS(i);
}
void BFS() {
	if (stack.size() == 0)
		return;
	for (int i = 0; i < stack.size();i++) {
		int a = stack.front();
		cout << a << ' ';
		stack.pop();
		for (int j = 0; j <= n;j++)
			if (matrix[a][j] == 1 && visit[j] == false) {
				stack.push(j);
				visit[j] = true;
			}
	}
	BFS();
}
int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m;i++) {
		int a, b;
		cin >> a >> b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	DFS(v);
	cout << '\n';
	for (int i = 0; i <= n;i++)
		visit[i] = false;
	stack.push(v);
	visit[v] = true;
	BFS();
	cout << '\n';
	return 0;
}
