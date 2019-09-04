#include <iostream>
#include <algorithm>
using namespace std;
int N, K, W[101], V[101], cache[100001][2] = {0};
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> W[i] >> V[i];
	for (int i = 0; i < N; i++) {
		for (int j = W[i]; j <= K; j++)
			cache[j][1] = max(cache[j][0], cache[j - W[i]][0] + V[i]);
		for (int j = W[i]; j <= K; j++)
			cache[j][0] = cache[j][1];
	}
	cout << cache[K][1] << endl;
	return 0;
}
