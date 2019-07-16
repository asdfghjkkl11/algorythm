#include <iostream>
using namespace std;
int main() {
	long long a, b, c, r;
	cin >> a >> b >> c;
	if (a == 0)
		r = (b >= c) ? -1 : 1;
	else
		if (b == c)
			r = -1;
		else {
			r = (a / (c - b)) + 1;
			if (r < 1)
				r = -1;
		}
	cout << r << endl;
	return 0;
}
