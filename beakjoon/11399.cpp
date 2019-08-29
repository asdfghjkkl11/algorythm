#include <iostream>
#include <algorithm>
using namespace std;
int N,arr[1000],result=0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 1; i < N; i++) {
		arr[i] += arr[i - 1];
		result += arr[i];
	}
	cout << result+arr[0] << endl;
	return 0;
}
