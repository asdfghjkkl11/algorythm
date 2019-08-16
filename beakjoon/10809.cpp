#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[101];
	int abc[26];
	cin >> str;
	for (int i = 0; i < 26; i++) {
		abc[i] = -1;
	}
	for (int i = 0; i < strlen(str);i++) {
		if ((int)str[i] > 95)
			str[i] -= 32;
		if (abc[((int)str[i] - 65) % 26] != -1)
			continue;
		abc[((int)str[i] - 65) % 26] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << abc[i]<< ' ';
	}
	cout << "\n";
}
