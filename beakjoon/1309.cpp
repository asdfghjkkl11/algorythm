#include <iostream>
using namespace std;
int main() {
	int N, M=1, L=1,result=0;
	cin >> N;
	for (int i = 0; i < N;i++) {
		result = ((L * 2) + M)%9901;
		M = L;
		L = result;
	}
	cout << result << endl;
	return 0;
}
