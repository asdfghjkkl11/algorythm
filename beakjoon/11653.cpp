#include <iostream>
#include <cmath>
using namespace std;
int N, m, i;
int main() {
	cin >> N;
	m = sqrt(N);
	for (i = 2; i <= m; i++)
		if (N%i == 0) {
			N /= i;
			cout << i << endl;
			i = 1;
			m = sqrt(N);
		}
	if(N!=1)
		cout << N << endl;
	return 0;
}
