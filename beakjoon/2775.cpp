#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int apart[15][14] = { {1,2,3,4,5,6,7,8,9,10,11,12,13,14} };
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 1; j <= a;j++) {
			for (int k = 0; k < b;k++) {
				if (apart[j][k] != 0)
					continue;
				if (k == 0)
					apart[j][k] = 1;
				else
					apart[j][k] = apart[j - 1][k] + apart[j][k - 1];
			}
		}
		cout << apart[a][b - 1] << "\n";
	}
}
