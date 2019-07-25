#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[101];
	cin >> str;
	int sum = 0;
	int len = strlen(str);
	for (int i = 0; i < len;i++) {
		if (str[i] == '=' || str[i] == '-')
			sum--;
		if (str[i] == 'j'&&i > 0 && (str[i - 1] == 'l' || str[i - 1] == 'n'))
			sum--;
		if (str[i] == 'z'&&i > 0 && i + 1 != len && (str[i - 1] == 'd'&&str[i + 1] == '='))
			sum--;
		sum++;
	}
	cout << sum << "\n";
}
