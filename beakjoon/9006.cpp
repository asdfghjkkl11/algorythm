#include <iostream>
#include <algorithm>
using namespace std;
int N, M, a, b, len;
pair<int, int> arr[2000000];
long long temp;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		len = a + b;
		for (int j = 0; j < a; j++) {
			cin >> M;
			arr[j] = { M,b };
		}
		for (int j = a; j < len; j++) {
			cin >> M;
			arr[j] = { M,a };
		}
		sort(arr, arr + len);
		temp = (long long)-a*b;
		for (int j = 0; j < len; j++) {
			temp += arr[j].second;
			if (temp >= 0) {
				cout << fixed;
				cout.precision(1);
				cout << (double)arr[j].first << endl;
				break;
			}
		}
	}
	return 0;
}
