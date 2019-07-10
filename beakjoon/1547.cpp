#include <iostream>
using namespace std;
int cup[4] = {0}, n;
int main() {
	cup[1] = 1;
	for (cin >> n; n--;) {
		int a, b;
		cin >> a >> b;
		int temp = cup[a];
		cup[a] = cup[b];
		cup[b] = temp;
	}
	for (int i = 0; i < 4;i++)
		if (cup[i] == 1)
			cout << i << endl;
	return 0;
}
