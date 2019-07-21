#include <iostream>
#include <queue>
using namespace std;
int metrix[100][100] = { 0 };
int check[100] = { 0 };
int m, n, answer = 0;
queue<char> x;
bool BFS() {
	int size = x.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < m; j++)
			if (metrix[x.front()][j] == 1) {
				if (check[j] != 1) {
					check[j] = 1;
					x.push(j);
				}
				metrix[x.front()][j] = 0;
				metrix[j][x.front()] = 0;
			}
		x.pop();
	}
	return (x.size() == 0)?false:true;
}
int main()
{
	cin >> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		metrix[x - 1][y - 1] = 1;
		metrix[y - 1][x - 1] = 1;
	}
	x.push(0);
	check[0] = 1;
	while (BFS()) {}
	for (int i = 1; i < m;i++)
		if (check[i] == 1)
			answer++;
	cout << answer << '\n';
	return 0;
}
