#include <iostream>
using namespace std;
int N, M, R, arr[10000];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	long long l = 0, r = 0xffffffff,m;
	while (l<=r) {
		m = (l + r) / 2;
		int C = 0;
		for (int i = 0; i < N;i++)
			C += arr[i] / m;
		if (C >= M) {
			l = m + 1;
			R = m;
		}
		else
			r = m-1;
	}
	cout << R << endl;
	return 0;
}
