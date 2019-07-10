#include <iostream>
#include <string>
using namespace std;
int arr[27] = { 0 };
int main() {
	string result = "";
	char s;
	int m = 0;
	while ((s = getchar()) != EOF) {
		if (s == ' ' || s == '\n')
			continue;
		int j = s - 'a';
		arr[j]++;
		if (arr[j] > m)
			m = arr[j];
	}
	for (int i = 0; i < 27; i++)
		if (m == arr[i])
			result += i+'a';
	cout << result << endl;;
	return 0;
}
