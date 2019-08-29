#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
struct cmp {
	bool operator()(int a,int b) {
		if(abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};
priority_queue<int, vector<int>, cmp>pq;
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
