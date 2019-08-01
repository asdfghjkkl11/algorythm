#include <iostream>
#include <queue>
using namespace std;
int N,a;
queue<int> que;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		que.push(i);
	for (int i = 1; i < N;i++) {
		que.pop();
		a = que.front();
		que.pop();
		que.push(a);
	}
	cout << que.front() << endl;
	return 0;
}
