#include <iostream>
#include <algorithm>
using namespace std;
int N,a=0, A[1000], cache[1001] = {0};
int main() {
	cin >> N;
	for (int i = 0; i < N;i++)
		cin >> A[i];
	for (int i = 0; i < N;i++) {
		int M = 0;
		for (int j = 0; j <= i; j++)
			if (A[j] < A[i])
				M = max(M, cache[j]);
		cache[i] = M + 1;
		a = max(a, cache[i]);
	}
	cout << a << endl;
	return 0;
}
