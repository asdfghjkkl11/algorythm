#include <iostream>
#include <cmath>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, int>m = { {"black",0},{ "brown",1 },{ "red",2 },{ "orange",3 },{ "yellow",4 },{ "green",5 },{ "blue",6 },{ "violet",7 },{ "grey",8 },{ "white",9 } };
	string s;
	long long int res = 0;
	for (int i = 0; i < 3;i++) {
		cin >> s;
		if (i == 2)
			res = res*pow(10, m[s]);
		else {
			res *= 10;
			res += m[s];
		}
	}
	cout << res << endl;
	return 0;
}
