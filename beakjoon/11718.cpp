#include <iostream>
using namespace std;
int main() {
	char str;
	str = getchar();
	while (str != -1) {
		putchar(str);
		str = getchar();
	}

	return 0;
}
