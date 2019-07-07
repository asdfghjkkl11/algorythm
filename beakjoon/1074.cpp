#include <iostream>
#include <cmath>
using namespace std;
int n, a, b;
int sz, result = 0;
void draw(int x, int y, int si) {
	if (si == 1)
		return;
	si /= 2;
	if ((x <= a&&x + si>a) && (y <= b&&y + si>b)) {
		draw(x, y, si);
	}
	else if ((x <= a&&x + si>a) && (y + si <= b&&y + si + si>b)) {
		result += si*si;
		draw(x, y + si, si);
	}
	else if ((x + si <= a&&x + si + si>a) && (y <= b&&y + si>b)) {
		result += 2 * si*si;
		draw(x + si, y, si);
	}
	else if ((x + si <= a&&x + si + si>a) && (y + si <= b&&y + si + si>b)) {
		result += 3 * si*si;
		draw(x + si, y + si, si);
	}
}
int main()
{
	cin >> n >> a >> b;
	sz = pow(2, n);
	draw(0, 0, sz);
	cout << result << endl;
	return 0;
}
