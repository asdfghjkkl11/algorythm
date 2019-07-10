#include<iostream>
using namespace std;
int n, a, b;
int main() {
	cin >> n;
	for (int t = 0; t < n; t++) {
		cin >> a >> b;
		int A = 0, B = 0;
		int A1, B1;
		for (int i = 0; i < a; i++) {
			cin >> A1;
			(A1 > A) ? A = A1 : A = A;
		}
		for (int i = 0; i < b; i++) {
			cin >> B1;
			(B1 > B) ? B = B1 : B = B;
		}
		(A >= B) ? cout << 'S' << endl : cout << 'B' << endl;
	}
	return 0;
}
