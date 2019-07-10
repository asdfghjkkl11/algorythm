#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int num[10] = {0};
	int n;
	cin >> n;
	int m = n,max=0;
	if (n == 0)
		num[0]+=2;
	while (n>0) {
		int i = n % 10;
		if (i == 6 || i == 9) {
			num[6]++;
			i = 6;
		}
		else
			num[i]+=2;
		if (num[max] <= num[i])
			max = i;
		n /= 10;
	}
	if (max == 6&& num[max]%2==1)
		cout << (num[max]/2)+1 << "\n";
	else
	    cout << num[max]/2<<"\n";
}
