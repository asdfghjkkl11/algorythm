#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	char ox[81];
	cin >> t;
	for (int i = 0; i < t;i++) {
		cin >> ox;
		int sum = 0;
		int *s =new int[strlen(ox)];
		for (int j = 0; j < strlen(ox);j++) {
			if (ox[j] == 'X')
				s[j] = 0;
			else {
				if (j != 0)
					s[j] = s[j - 1] + 1;
				else
					s[j] = 1;
			}
			sum += s[j];
		}
		cout << sum << "\n";
	}
	
	return 0;
}
