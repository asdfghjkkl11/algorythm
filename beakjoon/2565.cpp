#include <iostream>
#include <algorithm>
using namespace std;
int N, a, b, arr[501] = { 0 }, cache[501] = { 0 }, result = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[a] = b;
	}
	for (int i = 1; i <= 500; i++) {
		if (arr[i] == 0)continue;
		cache[i] = 1;
		for (int j = 1; j <= i; j++)
			if (arr[j] < arr[i])
				cache[i] = max(cache[i],cache[j]+1);
		result = max(result,cache[i]);
	}
	cout << N - result << endl;
	return 0;
}
