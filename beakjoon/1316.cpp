#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t, c = 0;
	char str[101];
	int abc[26];
	cin >> t;
	for (int i = 0; i < t;i++) {
		cin >> str;
		for (int j = 0; j < 26; j++) {
			abc[j] = 0;
		}
		int k = 0;
		while (str[k] != 0) {
			abc[(int)((int)str[k] % 97)] ++;
			if(k>0&&str[k]==str[k-1])
				abc[(int)((int)str[k] % 97)] --;
			k++;
		}
		bool b = true;
		for (int j = 0; j < 26; j++) {
			if (abc[j] > 1) {
				b = false;
				break;
			}
		}
		if (b)
			c++;
	}
	cout << c << "\n";
}
