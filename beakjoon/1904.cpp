#include <iostream>
using namespace std;
int N, arr[1000001];
int main() {
	cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 15746;
	}
	cout << arr[N] << endl;
	return 0;
}
