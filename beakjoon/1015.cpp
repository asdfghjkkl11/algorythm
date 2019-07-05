#include <iostream>
#include <algorithm>
using namespace std;
int N,A;
pair<int,int> arr[50];
int result[50];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		arr[i] = make_pair(A,i);
	}
	sort(arr,arr+N);
	for (int i = 0; i < N; i++)
		result[arr[i].second] = i;
	for(int i = 0; i < N; i++)
		cout << result[i] <<' ';
	cout << endl;
	return 0;
}
