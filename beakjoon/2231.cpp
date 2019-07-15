#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[1000001] = { 0 }, n;
int fd(int i) {
	int sum = i;
	while (i != 0) {
		sum += i % 10;
		i /= 10;
	}
	return sum;
}
int main()
{
	for (int i = 0; i < 1000001; i++) {
		int a = fd(i);
		if (a < 1000001)
			if(num[a]==0)
				num[a] = i;
	}
	cin >> n;
	cout << num[n] << endl;
	return 0;
}
