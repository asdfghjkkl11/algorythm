#include <iostream>
#include <queue>
using namespace std;
int metrix[1000][1000];
int m, n;
int Count = 0;
int c = 0;
queue<int> x;
queue<int> y;
void push(int a, int b) {
	x.push(a);
	y.push(b);
}
void pop() {
	x.pop();
	y.pop();
}
bool BFS() {
	int size = x.size();
	int C = c;
	for (int i = 0; i < size; i++) {
		if (y.front() - 1 >= 0)
			if (metrix[y.front() - 1][x.front()] == 0) {
				metrix[y.front() - 1][x.front()] = 1;
				c++;
				push(x.front(), y.front() - 1);
			}
		if (y.front() + 1 < n)
			if (metrix[y.front() + 1][x.front()] == 0) {
				metrix[y.front() + 1][x.front()] = 1;
				c++;
				push(x.front(), y.front() + 1);
			}
		if (x.front() - 1 >= 0)
			if (metrix[y.front()][x.front() - 1] == 0) {
				metrix[y.front()][x.front() - 1] = 1;
				c++;
				push(x.front() - 1, y.front());
			}
		if (x.front() + 1 < m)
			if (metrix[y.front()][x.front() + 1] == 0) {
				metrix[y.front()][x.front() + 1] = 1;
				c++;
				push(x.front() + 1, y.front());
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
	cin >> m >> n;
	
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			int t;
			cin >> t;
			metrix[j][i] = t;
			if (t != -1) {
				Count++;
			}
			if (t == 1) {
				push(i, j);
				c++;
			}
		}
	}
	while(c!=Count){
		bool t=BFS();
		answer++;
		if (t == false) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << answer << '\n';
	return 0;
}
