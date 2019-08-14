#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int h, w;
		h = c%a;
		w = (c / a) + 1;
		if (h == 0) {
			h = a;
			w--;
		}
		cout << h;
		if (w < 10)
			cout << 0;
		cout << w << "\n";
	}
}
