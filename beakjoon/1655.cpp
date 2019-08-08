#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, less<int>>lpq;
priority_queue<int, vector<int>, greater<int>>gpq;
int N, n;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		if (!gpq.empty()&&n>gpq.top())
			lpq.push(gpq.top());
		else
			lpq.push(n);
		if (!lpq.empty() && n<lpq.top())
			gpq.push(lpq.top());
		else
			gpq.push(n);
		if (i % 2) {
			lpq.pop();
			gpq.pop();
		}
		printf("%d\n",lpq.top());
	}
	return 0;
}
