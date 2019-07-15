#include <iostream>
using namespace std;
int n, k,coin;
int cache[10001] = {1};
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin;
		for (int i = 0; i <= k; i++)
			if (i - coin >= 0)
				cache[i] = cache[i] + cache[i - coin];
	}
	int result = cache[k];
	cout << result << endl;
	return 0;
}
