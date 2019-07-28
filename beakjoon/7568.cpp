#include <iostream>
using namespace std;
int n, a, b;
int x[50], y[50];
int Count[50] = { 0 };
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		x[i] = a;
		y[i] = b;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (x[j] > x[i] && y[j] > y[i])
				Count[i]++;
	for (int i = 0; i < n; i++)
		cout << Count[i]+1 << ' ';
	cout << endl;
	return 0;
}
