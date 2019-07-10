#include <iostream>
#include <deque>
using namespace std;
int main() {
	int n, m;
	unsigned long long k;
	unsigned long long fact = 1;
	deque<int>dque,eque;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		fact *= i;
		dque.push_back(i);
	}
	dque.push_back(n);
	if (m == 1) {
		cin >> k;
		k--;
		for (int i = n-1; i >=1; i--) {
			eque.push_back(dque[k/fact]);
			dque.erase(dque.begin()+(k/fact));
			k %= fact;
			fact /= i;
		}
		eque.push_back(dque[0]);
		for (int i = 0; i < n;i++)
			cout << eque[i] << ' ';
		cout << endl;
	}
	else {
		for (int i = 0; i < n;i++) {
			cin >> k;
			eque.push_back(k);
		}
		k = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < dque.size(); j++)
				if (dque[j] == eque[i]) {
					k += fact*j;
					dque.erase(dque.begin() + j);
					break;
				}
			if(n-i!=1)
			    fact /= n-1-i;
		}
		cout << k << endl;
	}
	return 0;
}
