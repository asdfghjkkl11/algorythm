#include <iostream>
using namespace std;
unsigned long long A, B, C, arr[33] = { 0 }, result = 1;
int main() {
	cin >> A >> B >> C;
	arr[1] = A % C;
	for (int i = 2; (1 << (i - 1)) <= B; i++)
		arr[i] = arr[i - 1] * arr[i - 1] % C;
	for (int i = 1; (1 << (i - 1)) <= B; i++)
		if (((1 << (i - 1)) & B) == (1 << (i - 1)))
			result = result * arr[i] % C;
	cout << result << endl;
	return 0;
}
