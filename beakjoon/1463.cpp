#include <iostream>
#include <algorithm>
using namespace std;
int n, cache[1000001] = {0};
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cache[i] = cache[i - 1] + 1;
		if (i % 2 == 0)
			cache[i] = min(cache[i], cache[i / 2] + 1);
		if (i % 3 == 0)
			cache[i] = min(cache[i], cache[i / 3] + 1);
	}
	cout << cache[n] << '\n';
	return 0;
}
