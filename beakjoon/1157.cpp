#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	char str[1000001];
	int abc[26];
	cin >> str;
	for (int i = 0; i < 26; i++)
		abc[i] = 0;
	int j = 0;
	while (str[j] != 0) {
		if ((int)str[j] > 95)
			abc[(int)((int)str[j] % 97)] ++;
		else
			abc[(int)((int)str[j] % 65)] ++;
		j++;
	}
	int max = 0;
	int index=1;
	for (int i = 1; i < 26; i++) {
		if (abc[i] >abc[max]) {
			max = i;
			index = 1;
		}
		else if (abc[i] ==abc[max]) {
			index++;
		}
	}
	if (index!=1)
		cout << "?";
	else
		cout << (char)(max+65);
	cout << "\n";
}
