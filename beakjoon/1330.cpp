#include <iostream>
using namespace std;
int main() {
	int N, M, R;
	cin >> N >> M;
	R = N - M;
	if(R==0)
		cout << "==" << endl;
	else if(R>0)
		cout << ">" << endl;
	else
		cout << "<" << endl;
	return 0;
}
