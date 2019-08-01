#include <iostream>
#include <vector>
#include <string>
using namespace std;
string str;
vector<char>v;
bool check() {
	v.clear();
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[')
			v.push_back(str[i]);
		else if (str[i] == ')'|| str[i] == ']') {
			if (v.size() == 0)
				return false;
			if ((str[i] == ')'&&v.back() == '(')|| (str[i] == ']'&&v.back() == '['))
				v.pop_back();
			else
				return false;
		}
	}
	return (v.size() == 0)?true:false;
}
int main() {
	while (true) {
		getline(cin, str);
		if (str.size() == 1)
			break;
		if (check())
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
