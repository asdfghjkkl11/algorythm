#include <iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	if(n==0)
		cout<<0<<endl;
	else
		cout<<(n/5)+(n/25)+(n/125)<<endl;
	return 0;
}
