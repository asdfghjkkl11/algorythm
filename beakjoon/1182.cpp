#include <iostream>
#include <algorithm>
using namespace std;
int A, B, result = 0;
int arr[21];
void DFS(int a,int b) {
	if (a == A&&b == B) {
		result++;
		return;
	}
	for (int i = a+1; i <= A;i++)
		if(a!=-1||i!=A)
			DFS(i,b+arr[i]);
}
int main() {
	cin >> A >> B;
	for (int i = 0; i < A; i++)
		cin >> arr[i];
	DFS(-1, 0);
	cout << result << endl;
	return 0;
}
