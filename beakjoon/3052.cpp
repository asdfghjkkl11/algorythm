#include <iostream>
using namespace std;
int A, arr[42] = {0};
int main() {
	for (int i = 1; i <= 10; i++) {
		cin >> A;
		arr[A % 42]++;
	}
	A = 0;
	for (int i = 0; i < 42; i++)
		if (arr[i] != 0)
			A++;
	cout << A << endl;
	return 0;
}
