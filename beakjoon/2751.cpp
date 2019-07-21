#include <iostream>
#include <vector>
using namespace std;
int *num;
void mergesort(int* v,int a,int b) {
	int c = (a + b) / 2;
	if (b - a != 1) {
		mergesort(v, a, c);
		mergesort(v, c, b);
	}
	else {
		return;
	}
	int *V = new int[b-a];
	int j = a, k = c;
	for (int i = 0; i < b - a;i++) {
		if (j != c&&k != b) {
			if (num[j] < num[k]) {
				V[i] = num[j];
				j++;
			}
			else {
				V[i] = num[k];
				k++;
			}
		}
		else if (j == c) {
			V[i] = num[k];
			k++;
		}
		else {
			V[i] = num[j];
			j++;
		}
	}
	for (int i = 0; i < b - a; i++) {
		num[a + i] = V[i];
	}
}
int main()
{
	int t;
	cin >> t;
	num=new int [t];
	for (int i = 0; i < t; i++) {
		cin >> num[i];
	}
	mergesort(num,0,t);
	for (int i = 0; i < t; i++) {
		cout << num[i] << '\n';
	}
}
