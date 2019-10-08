#include <iostream>
#include <cmath>

using namespace std;
int N, B, C,arr[1000000];
long long res = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> B >> C;
	res = N;
	for (int i = 0; i < N; i++) {
		arr[i] -= B;
		if (arr[i] > 0) {
			res += (arr[i] / C);
			if (arr[i] % C != 0)
				res++;
		}
	}
	cout << res << endl;
	return 0;
}
