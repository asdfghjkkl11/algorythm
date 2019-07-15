#include <iostream>
#include <queue>
using namespace std;
char metrix[100][100];
int m, n;
queue<char> x;
queue<char> y;
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
	for (int i = 0; i < size; i++) {
		if (y.front() - 1 >= 0)
			if (metrix[y.front() - 1][x.front()] == '1') {
				metrix[y.front()-1][x.front()] = '0';
				push(x.front(), y.front() - 1);
				if (x.back() + 1 == n&&y.back() + 1 == m)
					return false;
			}
		if (y.front() + 1 < m)
			if (metrix[y.front() + 1][x.front()] == '1') {
				metrix[y.front()+1][x.front()] = '0';
				push(x.front(), y.front() + 1);
				if (x.back() + 1 == n&&y.back() + 1 == m)
					return false;
			}
		if (x.front() - 1 >= 0)
			if (metrix[y.front()][x.front() - 1] == '1') {
				metrix[y.front()][x.front()-1] = '0';
				push(x.front() - 1, y.front());
				if (x.back() + 1 == n&&y.back() + 1 == m)
					return false;
			}
		if (x.front() + 1 < n)
			if (metrix[y.front()][x.front() + 1] == '1') {
				metrix[y.front()][x.front()+1] = '0';
				push(x.front() + 1, y.front());
				if (x.back() + 1 == n&&y.back() + 1 == m)
					return false;
			}
		pop();
	}
	if (x.size() == 0)
		return false;
	else
		return true;
}
int main()
{
	cin >> m >> n;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			char t;
			cin >> t;
			metrix[j][i] = t;
		}
	}
	metrix[0][0] = '0';
	push(0, 0);
	int answer = 1;
	while(BFS())
		answer++;
	cout << answer+1 << '\n';
	return 0;
}
