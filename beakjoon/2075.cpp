#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>>pq;
int N, n;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N*N; i++) {
		scanf("%d", &n);
		pq.push(n);
		if (pq.size() > N)
			pq.pop();	
	}
	printf("%d\n", pq.top());
	return 0;
}
