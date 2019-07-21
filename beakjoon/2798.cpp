#include <iostream>
#include <algorithm>
using namespace std;
int N, M, result = 0, arr[100];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int sum = 0;
	for (int i = 0; i < N - 2; i++) {
		sum += arr[i];
		for (int j = i + 1; j < N - 1; j++) {
			sum += arr[j];
			for (int k = j + 1; k < N; k++) {
				sum += arr[k];
				if (sum == M) {
					cout << sum << endl;
					return 0;
				}
				else if(sum>M){
				}
				else {
					result = max(result, sum);
				}
				sum -= arr[k];
			}
			sum -= arr[j];
		}
		sum -= arr[i];
	}
	cout << result << endl;
	return 0;
}
