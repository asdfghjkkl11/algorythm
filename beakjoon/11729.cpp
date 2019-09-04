#include <iostream>
using namespace std;
int N;
void move(int a, int b, int c) {
	if (a == 0)
		return;
	int d = 6 - b - c;
	move(a - 1, b, d);
	printf("%d %d\n",b,c);
	move(a - 1, d, c);
}
int main() {
	cin >> N;
	printf("%d\n", (1 << N) - 1);
	move(N, 1, 3);
	return 0;
}
