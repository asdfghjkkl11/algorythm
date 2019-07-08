#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int result=50;
string A, B;
int main() {
	cin >> A >> B;
	int s = B.length()-A.length();
	for (int i = 0; i <= s;i++) {
		int d = 0;
		for (int j = 0; j < A.length();j++)
			if (B[i + j] != A[j])
				d++;
		result = min(result, d);
	}
	cout << result << endl;
	return 0;
}
