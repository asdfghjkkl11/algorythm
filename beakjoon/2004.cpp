#include <iostream>
#include <algorithm>
using namespace std;
long long N, M;
long long num(long long a, int b) {
	long long result = 0;
	for (long long i = b; i <= a; i *= b)
		result += a / i;
	return result;
}
int main() {
	cin >> N >> M;
	long long A, B;
	A = num(N, 5) - num(M, 5) - num(N - M, 5);
	B = num(N, 2) - num(M, 2) - num(N - M, 2);
	cout << min(A, B) << endl;
	return 0;
}
