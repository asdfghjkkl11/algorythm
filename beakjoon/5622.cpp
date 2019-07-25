#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int abc[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	char str[16];
	cin >> str;
	int sum = 0;
	int len = strlen(str);
	for (int i = 0; i < len;i++) {
		sum += abc[((int)str[i]%65)]+1;
	}
	cout << sum << "\n";
}
