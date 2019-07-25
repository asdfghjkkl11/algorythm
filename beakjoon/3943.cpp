#include <iostream>
#include <algorithm>
using namespace std;
int t, n, result;
int cal(int a) {
	if (a == 1)
		return 1;
	return max(a,(a % 2)? cal((a * 3) + 1):cal(a / 2));
}
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		result = cal(n);
		printf("%d\n", result);
	}
	return 0;
}
