#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str[5],result="";
int main() {
	int len = 0;
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		int s = str[i].length();
		len = max(len, s);
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j].length() - 1 < i)
				continue;
			result += str[j][i];
		}
	}
	cout << result << endl;
	return 0;
}
