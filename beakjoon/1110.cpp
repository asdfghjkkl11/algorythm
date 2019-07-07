#include <iostream>
using namespace std;
int main() {
	int a,b[2],c=0,d,e;
	cin >> a;
	e = a;
	while (1) {
		b[0] = a / 10;
		b[1] = a % 10;
		d = b[0] + b[1];
		a = (b[1] * 10) + (d % 10);
		c++;
		if (a == e)
			break;
	}
	cout << c<<"\n";
	return 0;
}
