#include <iostream>
#include <queue>
using namespace std;
int N, M, arr[1000001];
void BFS() {
	queue<int> que;
	int time = 0;
	que.push(N);
	while (que.size() != 0) {
		int len = que.size();
		for (int i = 0; i < len; i++) {
			int T = que.front();
			que.pop();
			if (T < 0 || T>1000000 || arr[T] != -1)
				continue;
			arr[T] = time;
			if (T == M)
				return;
			que.push(T - 1);
			que.push(T + 1);
			que.push(T * 2);
		}
		time++;
	}
}
int main() {
	for (int i = 0; i <= 1000000; i++)
		arr[i] = -1;
	cin >> N >> M;
	BFS();
	cout << arr[M] << endl;
	return 0;
}
