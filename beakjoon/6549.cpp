#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
long long arr[100001] = { 0 }, result,now;
vector<long long>v;
int main() {
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		result = 0;
		v.clear();
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		arr[N] = 0;
		for (int i = 0; i <= N; i++) {
			while (!v.empty() && arr[i] < arr[v.back()]) {
				int t = v.back(),s;
				v.pop_back();
				s = (v.empty()) ? -1 : v.back();
				now = arr[t] * (i - 1 - s);
				result = max(result, now);
			}
			v.push_back(i);
		}
		cout << result << endl;
	}
	return 0;
}
