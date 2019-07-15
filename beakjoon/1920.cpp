#include <iostream>
#include <algorithm>
using namespace std;
int N, M, A[100000], B;
int Find(int n,int a,int b) {
	if (a >b)
		return 0;
	int mid = (a + b) / 2;
	if (A[mid] == n)
		return 1;
	else
		return (A[mid] > n)?Find(n,a,mid-1):Find(n,mid+1,b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B;
		cout << Find(B,0,N-1) << '\n';
	}
	return 0;
}
