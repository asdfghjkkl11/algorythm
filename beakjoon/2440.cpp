#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	for (int i = 0; i <a; i++) {
		for (int j = i; j<a; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
