#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str1, str2,result;
int len1,len2;
int main() {
	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();
	for (int i = 0; i < len1; i++) {
		result.push_back(str1[i]);
		if (result.length() >= len2 && str1[i] == str2[len2 - 1])
			if (result.substr(result.length()-len2, len2) == str2)
				for (int j = 0; j < len2;j++)
					result.pop_back();
	}
	if (result.length() == 0)
		result = "FRULA";
	cout << result << endl;
	return 0;
}
