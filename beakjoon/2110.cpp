#include <iostream>
#include <algorithm>
using namespace std;
int N, M, R, arr[200000];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	long long l = 0, r = 0xffffffff, m;
	while (l <= r) {
		m = (l + r) / 2;
		long long C = 1, T = 0;
		for (int i = 0; i < N; i++)
			if (arr[i] - arr[T] >= m)
				T = i, C++;
		if (C >= M)
			l = m + 1, R = m;
		else
			r = m - 1;
	}
	cout << R << endl;
	return 0;
}
