#include <iostream>
#include <algorithm>
using namespace std;
int N, M, cache[10100] = {0}, m[100], c[100],Size=0;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> m[i];
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		Size += c[i];
	}
	for (int i = 0; i < N; i++)
		for (int j = Size; j >=c[i]; j--)
			cache[j] = max(cache[j], cache[j - c[i]] + m[i]);
	for (int i = 0; i <= Size; i++)
		if (cache[i] >= M) {
			cout << i << endl;
			break;
		}
	return 0;
}
