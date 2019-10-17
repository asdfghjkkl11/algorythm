#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int N, A, B;
char C;
deque<int>gear[4];
bool visit[4];
void spin(int a, int b) {
	visit[a] = false;
	if (a > 0)
		if (gear[a - 1][2] != gear[a][6]&&visit[a-1])
			spin(a - 1, -b);
	if (a < 3)
		if (gear[a][2] != gear[a + 1][6]&&visit[a+1])
			spin(a + 1, -b);
	if (b == 1) {
		gear[a].push_front(gear[a].back());
		gear[a].pop_back();
	}
	else {
		gear[a].push_back(gear[a].front());
		gear[a].pop_front();
	}
}
int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++) {
			cin >> C;
			gear[i].push_back(C - '0');
		}
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++)
			visit[j] = true;
		cin >> A >> B;
		spin(A - 1, B);
	}
	int result = 0;
	for (int i = 0; i < 4; i++)
		result += (gear[i].front() << i);
	cout << result << endl;
	return 0;
}
