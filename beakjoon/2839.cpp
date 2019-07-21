#include <iostream>
using namespace std;
int main() {
	int a;
	int b, c, d, e,f,g;
	cin >> a;
	b = a / 5;
	c = a % 5;
	if (c == 0)
		cout << b << endl;
	else if (c == 1)
		if(b>0)
			cout << b+1 << endl;
		else
			cout << -1 << endl;
	else if (c == 2)
		if (b>1)
			cout << b + 2 << endl;
		else
			cout << -1 << endl;
	else if (c == 3)
		cout << b + 1 << endl;
	else if (c == 4)
		if (b>0)
			cout << b + 2 << endl;
		else
			cout << -1 << endl;
	return 0;
}
