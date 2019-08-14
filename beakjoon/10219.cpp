#include <iostream>
#include <algorithm>
using namespace std;
int t, n, m;
char gril[11][11];
int main()
{
	for (cin >> t; t--;) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				gril[i][j] = c;
			}
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--)
				cout << gril[i][j];
			cout << endl;
		}
	}
	return 0;
}
