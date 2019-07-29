#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[100000], result = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
		result = max(result, arr[i] * (N - i));
	cout << result << endl;
	return 0;
}
