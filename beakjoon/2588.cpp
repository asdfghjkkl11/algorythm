#include <iostream>
using namespace std;
int A, B;
int main() {
	cin >> A >> B;
	cout << A*(B % 10) << endl;
	cout << A*((B / 10) % 10) << endl;
	cout << A*(B / 100) << endl;
	cout << A*B << endl;
	return 0;
}
