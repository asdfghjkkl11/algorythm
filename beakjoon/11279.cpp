#include <iostream>
#include <queue>
using namespace std;
priority_queue<int>pq;
int N, n;
int main() {
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		if (n == 0)
			if (pq.empty())
				printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		else
			pq.push(n);
	}
	return 0;
}
