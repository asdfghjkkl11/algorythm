#include <iostream>
#include <vector>
using namespace std;
vector<int> V;
int N;
int main() {
	for (int i = 0; V.size()!=10000; i++) {
		int a = i;
		while (a!=0) {
			if (a % 1000 == 666) {
				V.push_back(i);
				break;
			}
			a /= 10;
		}
	}
	cin >> N;
	cout << V[N - 1] << endl;
	return 0;
}
