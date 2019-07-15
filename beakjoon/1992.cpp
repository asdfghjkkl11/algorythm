#include <iostream>
#include <string>
using namespace std;
int mat[64][64];
int n;
string s = "";
void quadtree(int x, int y, int m) {
	bool tf = true;
	int a = mat[x][y];
	for (int i = x; i < x + m; i++) {
		for (int j = y; j < y + m; j++)
			if (mat[i][j] != a) {
				tf = false;
				break;
			}
		if (tf == false)
			break;
	}
	if (tf == true) {
		if (a == 1)
			s += '1';
		else
			s += '0';
	}
	else {
		int size = m / 2;
		s += '(';
		quadtree(x, y, size);
		quadtree(x, y + size, size);
		quadtree(x + size, y, size);
		quadtree(x + size, y + size, size);
		s += ')';
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			mat[i][j] = a - 48;
		}
	quadtree(0, 0, n);
	cout << s << endl;
	return 0;
}
