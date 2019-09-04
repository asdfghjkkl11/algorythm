#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> V;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		if (V.empty() || V.back() < M)
			V.push_back(M);
		else {
			auto iter = lower_bound(V.begin(), V.end(), M);
			*iter = M;
		}
	}
	cout << V.size() << endl;
	return 0;
}
