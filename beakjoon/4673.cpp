#include <iostream>
using namespace std;
int d(int a) {
	int b[5],i=0;
	int c = a;
	while (c!=0) {
		b[i] = c % 10;
		c = c / 10;
		i++;
	}
	int result = a;
	for (int j = 0; j < i;j++)
		result += b[j];
	return result;
}
int main() {
	bool a[10001] = {false};
	for (int i = 1; i < 10001;i++) {
		int b = d(i);
		if (b < 10001)
			a[b] = true;
	}
	for (int i = 1; i < 10001; i++)
		if (a[i] == false)
			cout << i << "\n";
	return 0;
}
