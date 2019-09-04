#include <iostream>
using namespace std;
int main() {
	int a, b = 0;
	char c;
	cin >> a;
	getchar();
	for (int i = 0; i <a; i++) {
		c = getchar();
		b +=(int)c-48;
	}
	cout << b << endl;
	return 0;
}
