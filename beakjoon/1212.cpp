#include <iostream>
#include <string>
using namespace std;
string con[8] = {"000","001","010","011","100","101","110","111"};
int main() {
	string str, result;
	cin >> str;
	for (int i = 0; i < str.length();i++)
		result += con[str[i]-'0'];
	int c = 0;
	while (result[c] == '0'&&c!=result.length()-1)
		c++;
	cout << result.substr(c) << endl;
	return 0;
}
