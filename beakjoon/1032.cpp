#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, S;
string arr[50];
bool tf[50] = {0};
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	S = arr[0].length();
	for (int i = 0; i < S; i++)
		tf[i] = true;
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < N; j++) {
			bool T = (arr[0][i]==arr[j][i]) ? true: false;
			tf[i] &= T;
		}
	}
	string result = "";
	for (int i = 0; i < S; i++)
		if (tf[i])
			result += arr[0][i];
		else
			result += "?";
	cout <<result<< endl;
	return 0;
}
