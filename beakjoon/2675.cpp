#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,c;
	char str[101];
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> c;
		cin >> str;
		for (int j = 0; j < strlen(str);j++)
			for (int k = 0; k < c;k++)
				cout << str[j];
		cout << "\n";
	}
}
