#include <iostream>
using namespace std;
int A, B, X, res=1;
int main() {
	cin >> A >> B >> X;
	X -= A;
	res += X / (A - B);
	if (X % (A - B) != 0)
		res++;
	cout << res;
	return 0;
}
