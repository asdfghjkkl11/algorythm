#include<iostream>
using namespace std;
int n, N, sum;
int num[100000];
int main() {
	cin >> n;
	for (int t = 1; t <= n; t++) {
		cin >> N >> sum;
		for (int i = 0; i < N;i++)
			cin >> num[i];
		int result = 0, mid = N/2;
		int a = mid - 1, b = mid;
		while (a>=0&&b<N) {
			if (num[a] + num[b] == sum)
				result++;
			if (num[a] + num[b] > sum)
				a--;
			else
				b++;
		}
		cout << "Case #" << t << ": " << result << endl;
	}
	return 0;
}
