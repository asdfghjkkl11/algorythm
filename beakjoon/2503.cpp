#include <iostream>
#include <map>
using namespace std;
int N, result = 0;
int num[100], s1[100], b1[100];
bool check(map<int, int>m) {
	for (int j = 0; j < N; j++) {
		int s2 = 0, b2 = 0;
		int n[4];
		n[1] = num[j] / 100, n[2] = (num[j] % 100) / 10, n[3] = num[j] % 10;
		for (int k = 1; k <= 3; k++)
			if (m[n[k]] != 0)
				if (m[n[k]] == k)
					s2++;
				else
					b2++;
		if (s2 != s1[j] || b2 != b1[j])
			return false;
	}
	return true;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i] >> s1[i] >> b1[i];
	for (int i = 100; i < 1000; i++) {
		int a1 = i / 100, b1 = (i % 100) / 10, c1 = i % 10;
		if (a1 == b1 || a1 == c1 || b1 == c1 || a1 == 0 || b1 == 0 || c1 == 0)
			continue;
		map<int, int>m;
		m[a1] = 1;
		m[b1] = 2;
		m[c1] = 3;
		if (check(m))
			result++;
	}
	cout << result << endl;
	return 0;
}
