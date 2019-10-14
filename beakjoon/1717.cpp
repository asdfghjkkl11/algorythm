#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, arr[1000001], A, B, C;
int find(int a) {
	while (arr[a] != -1)
		a = arr[a];
	return a;
}
void join(int a, int b) {
	int t = find(a), s = find(b);
	if (t == s)
		return;
	int m = min(t, s);
	arr[max(t, s)] = m;
	if (m != a)
		arr[a] = m;
	if (m != b)
		arr[b] = m;
}
bool check(int a, int b) {
	return (find(a) == find(b));
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++)
		arr[i] = -1;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		if (A == 1)
			if (check(B, C))
				printf("YES\n");
			else
				printf("NO\n");
		else
			join(B, C);
	}
	return 0;
}
