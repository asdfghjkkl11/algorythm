
#include<stdio.h>
#include<stdlib.h>
void main() {
	FILE* stream;
	int file_state;	
	int A, B, D;
	void Extended_Euclid(int, int);
	//file I/O
	stream = fopen("Euclid.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	while (fscanf(stream, "%d %d", &A, &B) != EOF) {
		Extended_Euclid(A,B);
	}

	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
	
}
void Extended_Euclid(int r1, int r2) {
	int s, s1=1, s2=0;
	int t, t1=0, t2=1;
	int r,q;
	while (r2!=0) {
		r =r1 / r2;
		s = s1;
		s1 = s2;
		s2 = s - r * s2;
		t = t1;
		t1 = t2;
		t2 = t - r * t2;
		q = r2;
		r2 = r1 - r*r2;
		r1 = q;
	}
	if(r1>r2)
		printf("%d %d %d\n",s1,t1,r1);
	else
		printf("%d %d %d\n", t1, s1, r1);
}
