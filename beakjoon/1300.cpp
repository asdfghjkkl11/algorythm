#include <iostream>
#include <algorithm>
using namespace std;
int N, M, R, l = 0, r, mid, c;
int main() {
	cin >> N >> M;
	r = M;
	while (l <= r) {
		mid = (l + r) / 2;
		c = 0;
		for (int i = 1; i <= N; i++)
			c += min(mid / i, N);
		if (c < M)
			l = mid + 1;
		else{
			r = mid - 1;
			R = mid;
		}
	}
	cout << R << endl;
	return 0;
}
