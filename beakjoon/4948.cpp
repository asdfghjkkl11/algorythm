#include <iostream>
using namespace std;
int n;
int num[246913];
int main()
{
	for (int i = 0; i < 246913; i++)
		num[i] = 1;
	num[0] = 0, num[1] = 0;
	for (int i = 2; i < 246913; i++)
		if (num[i] == 1)
			for (int j = i * 2; j < 246913; j += i)
				num[j] = 0;
	cin >> n;
	while(n!=0) {
		int count = 0;
		for (int i = n+1; i <= 2 * n; i++)
			if (num[i] == 1)
				count++;
		printf("%d\n",count);
		cin >> n;
	}
	return 0;
}
