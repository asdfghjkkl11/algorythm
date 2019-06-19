#include<iostream>
using namespace std;
bool che[1000001];
int main() {
	long long mi, ma;
	cin >> mi >> ma;
	for (long long i = 2; i*i <= ma; i++) {
		long long j = i*i;
		long long start = 0;
		if (mi%j == 0)
			start = 0;
		else
			start = ((mi / j)*j + j) - mi;
		while (start <= ma - mi) {
			che[start] = true;
			start += j;
		}
	}
	long long result = 0;
	for (int i = 0; i <= ma - mi; i++)
		if (!che[i])
			result++;
	cout << result << endl;
	return 0;
}
