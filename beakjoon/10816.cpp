#include <iostream>
#include <unordered_map>
using namespace std;
int N, M, A;
int main() {
	unordered_map<int, int> UM;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		UM[A]++;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &A);
		printf("%d ", UM[A]);
	}
	return 0;
}
