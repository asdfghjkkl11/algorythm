#include<iostream>
#include<string.h>
using namespace std;
char s[501];
int main()
{
	do {
		cin.getline(s,501);
		if (s[0] != 'E' || s[1] != 'N' || s[2] != 'D') {
			for (int i = strlen(s) - 1; i >= 0; i--) {
				cout << s[i];
			}
			cout << endl;
		}
	} while (s[0]!='E'||s[1]!='N'||s[2]!='D');
	return 0;
}
