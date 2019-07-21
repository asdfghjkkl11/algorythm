#include <iostream>
#include <algorithm>
using namespace std;
int n;
int stair[301], cache[301][301];
int str(int a, int b) {
	if (b < 0)
		return 0;
	if (b == 0)
		return stair[b];
	if (cache[a][b] != 0)
		return cache[a][b];
	if (a - b == 1)
		return cache[a][b] = str(b, b - 2) + stair[b];
	return cache[a][b] = max(str(b, b - 1), str(b, b - 2)) + stair[b];
}
int main() {
	cin >> n;
	stair[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];
	int result = str(n, n);
	cout << result << endl;
}
