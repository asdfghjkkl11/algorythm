#include <iostream>
#include <algorithm>
using namespace std;
int N, K, arr[1000000];
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int c = 0, i = N - 1;
	while (K != 0) {
		c += K / arr[i];
		K %= arr[i];
		i--;
	}
	cout << c << endl;
	return 0;
}
