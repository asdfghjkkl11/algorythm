#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[11], psmd[4],MIN=1000000001,MAX=-1000000001;
void DFS(int T,int r) {
	if (T == N) {
		MIN = min(MIN, r);
		MAX = max(MAX, r);
		return;
	}
	for (int i = 0; i < 4;i++) {
		if (psmd[i] != 0) {
			psmd[i]--;
			int s;
			switch (i)
			{
			case 0:
				s = r + arr[T];
				break;
			case 1:
				s = r - arr[T];
				break;
			case 2:
				s = r * arr[T];
				break;
			case 3:
				s = r / arr[T];
				break;
			}
			DFS(T + 1,s);
			psmd[i]++;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> psmd[i];
	DFS(1,arr[0]);
	cout << MAX << endl;
	cout << MIN << endl;
	return 0;
}
