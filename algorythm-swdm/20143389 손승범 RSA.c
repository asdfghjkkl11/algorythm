
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int c = 0;
struct carmichael {
	int carm[300];
}C;
void main() {
	FILE* stream;
	int file_state;	
	int e, n,C1,i,M;
	int Q,P,E,I,t,Ex;
	int Extended_Euclid(int, int);
	void MR();
	int Mod(int, int,int);
	//memory prime number
	MR();
	//file I/O
	stream = fopen("RSA.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	while (fscanf(stream, "%d %d %d", &e, &n,&C1) != EOF) {
		//find prime numbers n=P*Q
		for (i = 2; i < c;i++) {
			if (n%i==0) {
				P = i;
				Q = n / i;
				break;
			}
		}
		//find Euler's function
		E = n - P - Q + 1;
		I = 1;
		t = e;
		//use extended euclid
		Ex=Extended_Euclid(e,E); 
		//find message
		M=Mod(C1,Ex,n);
		printf("%d\n",M);
	}

	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
}
void MR() {
	//memory prime number under 1000
	int i,j;
	for (i = 2; i < 300;i++) {
		for (j = 2; j < i;j++) {
			if (i%j==0) {
				break;
			}
		}
		if (j==i) {
			C.carm[c] = i;
			c++;
		}
	}
}
int Mod(int x,int n, int C) {
	int i,t=1;
	//save r[i]==x^2i
	int *r = (int*)malloc(sizeof(int)*((int)log2(n)));


	*r = x%C;
	for (i = 1; i <= (int)log2(n);i++) {
		*(r + i) = (*(r + i - 1) * *(r + i - 1)) %C;
	}
	//calculate x^n=x^1*x^2.....
	for (i = (int)log2(n); i>=0; i--) {
		if ((int)pow((double)2, (double)i)<=n) {
			t = ((t * *(r + i))%C);
			n =n- (int)pow((double)2, (double)i);
		}
	}
	return t%C;
}

int Extended_Euclid(int r2, int r1)
{
	int r, q, s, s1 = 1, s2 = 0, t, t1 = 0, t2 = 1, tmp = r1;

	while (r2)
	{
		q = r1 / r2;
		r = r1%r2;
		s = s1 - q*s2;
		t = t1 - q*t2;

		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}


	if (r1 == 1) 
	{
		if (t1 < 0)
			t1 += tmp;
		return t1;
	}

	return 0;
}
