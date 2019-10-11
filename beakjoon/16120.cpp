#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
string str,s;
int main() {
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		s.push_back(str[i]);
		if (str[i] == 'P'&&s.length()>3) {
			if (s.substr(s.length() - 4, 4) == "PPAP") {
				for (int j = 0; j < 4; j++)
					s.pop_back();
				i--;
			}
		}	
	}
	if (s == "P")
		cout << "PPAP" << endl;
	else
		cout << "NP" << endl;
	return 0;
}
