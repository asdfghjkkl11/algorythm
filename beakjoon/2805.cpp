#include <iostream>
using namespace std;
int N, M, R, arr[1000000];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	long long l = 0, r = 0xffffffff,m;
	while (l<=r) {
		m = (l + r) / 2;
		long long C = 0,T;
		for (int i = 0; i < N; i++) {
			T = (arr[i] - m < 0) ? 0 : arr[i] - m;
			C += T;
		}
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
