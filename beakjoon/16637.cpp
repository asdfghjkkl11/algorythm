#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
int N;
string str;
long long result = LLONG_MIN;
long long cal(char op, long long a, long long b) {
	switch (op) {
	case '+':
		return a + b;
	case '*':
		return a * b;
	case '-':
		return a - b;
	}
	return b;
}
void dfs(int a, long long b) {
	if (a == N + 1) {
		result = max(result, b);
		return;
	}
	char op = (a == 0) ? '/' : str[a - 1];
	dfs(a + 2, cal(op, b, str[a] - '0'));
	if (a + 4 <= N + 1)
		dfs(a + 4, cal(op, b, cal(str[a + 1], str[a] - '0', str[a + 2] - '0')));
}
int main() {
	cin >> N >> str;
	dfs(0, 0);
	cout << result << endl;
	return 0;
}
