#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int nm = 0, np = 0, nz = 0;
int num[2187][2187];
int count(int x, int y, int size) {
	int sum[9];
	int rsize = size / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (size != 3)
				sum[i * 3 + j] = count(x + (i*rsize), y + (j*rsize), rsize);
			else
				sum[i * 3 + j] = num[x + i][y + j];
	int t = sum[0];
	for (int i = 0; i < 9; i++)
		if (sum[i] != t&&t!=2) {
			t = 2;
			break;
		}
	if (t == 2)
		for (int i = 0; i < 9; i++)
			switch (sum[i])
			{
			case -1:
				nm++;
				break;
			case 0:
				nz++;
				break;
			case 1:
				np++;
				break;
			}
	return t;
}
void recrut() {
	int r = count(0, 0, n);
	switch (r)
	{
	case -1:
		nm++;
		break;
	case 0:
		nz++;
		break;
	case 1:
		np++;
		break;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			num[i][j] = a;
		}
	}
	recrut();
	cout << nm << endl << nz << endl << np << endl;
	return 0;
}
