#include <iostream>
#include <queue>
using namespace std;
int metrix[100][100][100];
int m, n,h;
int Count = 0;
int c = 0;
queue<int> x;
queue<int> y;
queue<int> z;
void push(int a, int b, int d) {
	x.push(a);
	y.push(b);
	z.push(d);
}
void pop() {
	x.pop();
	y.pop();
	z.pop();
}
bool BFS() {
	int size = x.size();
	int C = c;
	for (int i = 0; i < size; i++) {
		if (y.front() - 1 >= 0)
			if (metrix[z.front()][y.front() - 1][x.front()] == 0) {
				metrix[z.front()][y.front() - 1][x.front()] = 1;
				c++;
				push(x.front(), y.front() - 1, z.front());
			}
		if (y.front() + 1 < n)
			if (metrix[z.front()][y.front() + 1][x.front()] == 0) {
				metrix[z.front()][y.front() + 1][x.front()] = 1;
				c++;
				push(x.front(), y.front() + 1, z.front());
			}
		if (x.front() - 1 >= 0)
			if (metrix[z.front()][y.front()][x.front() - 1] == 0) {
				metrix[z.front()][y.front()][x.front() - 1] = 1;
				c++;
				push(x.front() - 1, y.front(), z.front());
			}
		if (x.front() + 1 < m)
			if (metrix[z.front()][y.front()][x.front() + 1] == 0) {
				metrix[z.front()][y.front()][x.front() + 1] = 1;
				c++;
				push(x.front() + 1, y.front(), z.front());
			}
		if (z.front() - 1 >= 0)
			if (metrix[z.front() - 1][y.front()][x.front()] == 0) {
				metrix[z.front() - 1][y.front()][x.front()] = 1;
				c++;
				push(x.front(), y.front(), z.front() - 1);
			}
		if (z.front() + 1 < h)
			if (metrix[z.front() + 1][y.front()][x.front()] == 0) {
				metrix[z.front() + 1][y.front()][x.front()] = 1;
				c++;
				push(x.front(), y.front(), z.front() + 1);
			}
		pop();
	}
	if (C == c)
		return false;
	else
		return true;
}
int main()
{

	int answer = 0;
	cin >> m >> n>>h;
	for (int k = 0; k < h;k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				int t;
				cin >> t;
				metrix[k][j][i] = t;
				if (t != -1) {
					Count++;
				}
				if (t == 1) {
					push(i, j,k);
					c++;
				}
			}
		}
	}
	while (c != Count) {
		bool t = BFS();
		answer++;
		if (t == false) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << answer << '\n';
	return 0;
}
