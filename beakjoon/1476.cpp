#include<iostream>
using namespace std;
int e, s, m;
int te = 1, ts = 1, tm = 1, tn = 1;
int main()
{
	cin >> e >> s >> m;
	while (e!=te||s!=ts||m!=tm) {
		te++; ts++; tm++; tn++;
		if (te == 16)
			te = 1;
		if (ts == 29)
			ts = 1;
		if (tm == 20)
			tm = 1;
	}
	cout << tn << endl;
	return 0;
}
