#include <iostream>
#include <algorithm>
using namespace std;
int N, a = 0, A[1000], cache[1001][2] = { 0 };
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++) {
		int M = 0;
		for (int j = 0; j <= i; j++)
			if (A[j] < A[i])
				M = max(M, cache[j][0]);
		cache[i][0] = M + 1;
	}
	for (int i = N - 1; i >= 0; i--) {
		int M = 0;
		for (int j = N - 1; j >= i; j--)
			if (A[j] < A[i])
				M = max(M, cache[j][1]);
		cache[i][1] = M + 1;
		a = max(a, cache[i][0] + cache[i][1]);
	}
	cout << a -1 << endl;
	return 0;
}
