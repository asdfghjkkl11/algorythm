
#include<stdio.h>
#include<stdlib.h>
struct node {
	int link[30];
	int colored;
	int size;
};

void main() {
	FILE* stream;
	int file_state;
	int n, o[30],t[30],i,r;
	int two_color(int,int[],int[]);
	//file I/O
	stream = fopen("Color.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	while (!feof(stream)) {
		fscanf(stream, "%d", &n);
		for (i = 0; i < n; i++) {
			fscanf(stream, "%d %d", &o[i], &t[i]);
		}
		r = two_color(n, o, t);
		if (r == 1) {
			printf("two-color graph\n");
		}
		else
			printf("not two-color graph\n");
	}
	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
}
int two_color(int n, int o[], int t[]) {
	struct node L[30] = { -1 };
	int i,j,k, l[30] = { 0 };
	int coloring(struct node[], int,int,int);
	for (i = 0; i < 30;i++) {
		L[i].colored=0;
		L[i].size = 0;
		for (j = 0; j < 30; j++) {
			L[i].link[j] = 0;
		}
	}
	for (i = 0; i < n;i++) {
		l[o[i]]++;
		l[t[i]]++;
	}
	for (i = 0; i < n; i++) {
		L[o[i]].link[L[o[i]].size] = t[i];
		L[t[i]].link[L[t[i]].size] = o[i];
		L[o[i]].size++;
		L[t[i]].size++;
	}
	i = 0;
	while (l[i] != 0) {
		i++;
	}
	
	return coloring(L,i,0,-1);
}
int coloring(struct node L[],int n,int i,int c){
	int j, k,s,p;
	if (n == i)
		return 1;
	for (j = 1; j < 3; j++) {
		s = 1;
		L[i].colored = j;
		for (k = 0; k < L[i].size;k++) {
			if (L[L[i].link[k]].colored == j)
				s = 0;
		}
		for (k = 0; k < n;k++) {
			printf("%d ",L[k].colored);
		}
		printf("\n");
		p = i+1;
		if(s==1)
			return coloring(L, n, p, j);
	}
	return 0;
}
