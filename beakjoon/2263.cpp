#include<iostream>
#include<cmath>
using namespace std;
int n, root;
int inorder[100000], preorder[100000], postorder[100000];
int index = 0;
void cal(int a, int b, int c, int d) {
	int root = postorder[d - 1];
	int in = 0;
	for (in = a; in < b; in++)
		if (inorder[in] == root)
			break;
	if (in == b)
		return;
	preorder[index] = root;
	index++;
	cal(a, in, c, c + in - a);
	cal(in + 1, b, c + in - a, d - 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	cal(0, n, 0, n);
	for (int i = 0; i < n; i++)
		cout << preorder[i] << ' ';
	cout << endl;
	return 0;
}
