#include <iostream>
#include <vector>
using namespace std;
int yut[3][4], sum[3] = {0};
int main()
{
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 4;j++) {
			int a;
			cin >> a;
			yut[i][j] = a;
			sum[i] += a;
		}
	}
	for (int i = 0; i < 3;i++) {
		switch (sum[i])
		{
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "A\n";
			break;
		case 4:
			cout << "E\n";
			break;
		}
	}
	return 0;
}
