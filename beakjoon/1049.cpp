#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, M, md = 1001, mn = 1001;
int das[50], num[50];
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> das[i] >> num[i];
		md = (das[i] < md) ? das[i] : md;
		mn = (num[i] < mn) ? num[i] : mn;
	}
	int X = N / 6, Y = N % 6, result;
	if (md > mn * 6)
		result = mn*N;
	else if (md < mn*Y)
		result = (X + 1)*md;
	else
		result = (X*md) + (Y*mn);
	cout << result << endl;
	return 0;
}
