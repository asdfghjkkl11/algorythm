#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b, c, d;
string Plus(string str1, string str2) {
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	str1.resize(max(str1.length(), str2.length()), 0);
	str2.resize(max(str1.length(), str2.length()), 0);
	string result = "", cache = "";
	result.resize(str1.length() + 1, 0);
	cache.resize(str1.length() + 1, 0);
	for (int i = 0; i < str1.length(); i++) {
		int t = cache[i];
		if (str1[i] != 0)
			t += str1[i] - '0';
		if (str2[i] != 0)
			t += str2[i] - '0';
		cache[i + 1] = t / 10;
		result[i] = (t % 10) + '0';
	}
	if (cache[str1.length()] != 0)
		result[str1.length()] = cache[str1.length()] + '0';
	else
		result.resize(str1.length(), 0);
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	cout << Plus(a, c) << endl;
	return 0;
}
