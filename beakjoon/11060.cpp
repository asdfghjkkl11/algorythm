#include <iostream>
#include <algorithm>
using namespace std;
int n,result;
int cache[2][1000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cache[0][i];
		cache[1][i] = 100001;
	}
	cache[1][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < cache[0][i]; j++)
			cache[1][i + j + 1] = min(cache[1][i + j + 1], cache[1][i]+1);
	result = (cache[1][n-1] >= 100001) ? -1 : cache[1][n - 1];
	cout << result<< endl;
	return 0;
}
