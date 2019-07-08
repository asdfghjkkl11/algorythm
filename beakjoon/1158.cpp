#include <iostream>
#include <vector>
using namespace std;
int main()
{
		int n, k;
		cin >> n >> k;
		k--;
		vector<int> v,v1;
		for (int i = 0; i < n;i++)
			v.push_back(i+1);
		int index = k;
		while (v.size() != 0) {
			int a =v[index];
			v1.push_back(a);
			v.erase(v.begin() + index);
			if (v.size() == 0)
				break;
			index += k;
			index %= v.size();
		}
		cout << "<";
		for (int i = 0; i < v1.size(); i++) {
			cout << v1[i];
			if (i != v1.size() - 1)
				cout << ", ";
		}
		cout <<">" <<endl;
}
