#include <iostream>
#include <string>
#include <vector>
using namespace std;
int result = 0, num = 0, pm = 1;
string str;
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			result += pm * num;
			num = 0;
			if (str[i] == '-')
				pm = -1;
		}
		else {
			num *= 10;
			num += str[i] - '0';
		}
	}
	result += pm * num;
	cout << result << endl;
	return 0;
}
