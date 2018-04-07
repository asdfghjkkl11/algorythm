/* 
This program disprove bigger elephant is smarter. recieve and select data to disprove it.
in program, find data like search tree. first, each data find route satisfy condition (smarter but not bigger).
and go to each data and find again. if data has no route, return data stack to parent data.
parent data find most longer route and return it's parent data. finally root data has longest data stack.
main function print data and order to disprove bigger elephant is smarter.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//struct to count and stack data tree
struct ele {
	int count;
	int stack[1000];
}con[1000] = { 0 };
//data of elephant and linked
int count[1000][1000], W[1000], S[1000];
struct ele search(int, int);
void main() {
	FILE* stream;
	struct ele define(int[], int[], int);
	struct ele result;
	int file_state;
	int i, j, c = 0;
	//recieve data from file
	stream = fopen("elephant.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	while (!feof(stream)) {
		fscanf(stream, "%d %d", &W[c], &S[c]);
		c++;
	}
	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
	//find data to disprove
	result = define(W, S, c);
	//print data
	for (i = 0; i < c; i++) {
		printf("%d %d ", W[i], S[i]);
		for (j = 0; j < result.count;j++) {
			if (i == result.stack[j])
				printf(" (%d)",j+1);
		}
		printf("\n");
	}
}
struct ele define(int W[], int S[], int s) {
	//define function get each data's can have the longest data stack, find and return the longest of them
	struct ele com[1000], max = {0};
	int i, j;
	for (i = 0; i <s; i++) {
		for (j = 0; j < s; j++) {
			if (W[j] < W[i] && S[j] > S[i]) {
				//linked data
				count[i][j] = 1; 
			}
		}
	}	
	for (i = 0; i < s; i++) {
		//find data has the longest data stack
		com[i] = search(s, i);
		if (i == 0)
			max = com[0];
		else if (com[i].count > max.count)
			max = com[i];
	}
	return max;
}
struct ele search(int s, int n) {
	//search function find the longest data stack of n.if data has links, search having the longest data stack
	struct ele max = {0}, a[1000];
	int i, c = 0, mi, j;
	for (i = 0; i < s; i++) {
		if (count[n][i] == 1) {
			c++;
			mi = i;
			a[i] = search(s, i);
		}
	}
	if (c == 0) {
		max.stack[max.count] = n;
		max.count++;
		return max;
	}
	max = a[mi];
	for (i = 0; i < s; i++) {
		if (a[i].count > max.count)
			max = a[i];
	}
	max.stack[max.count] = n;
	max.count++;
	return max;
}
