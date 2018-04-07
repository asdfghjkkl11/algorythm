#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
this program sort numbers like pencake. find biggest number and flip the numbers between top and the biggest number.
and flip again all numbers. so the biggest number go to the bottom.
*/
void main() {
	FILE* stream;
	int file_state;
	int cake[30];
	char str[100];
	int i,j,count;
	void flip(int [],int);
	//bring data using file to string. so converse string to integer.
	stream = fopen("pencake.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	while (!feof(stream)) {
		fgets(str, sizeof(str), stream);
		j = 0;
		count = 0;
		for (i = 0; i < strlen(str);i++) {
			if ((str[i]==' ')|| (str[i] == '\n')) {
				if((i-j)==2){
					cake[count] = ((10 * (str[i - 2]-'0')) + (str[i - 1]-'0'));
				}
				else {
					cake[count] =str[i - 1]-'0';
				}
				j = i+1;
				count++;
			}
		}
		//flip function sort numbers and print result.
		flip(cake,count);
		
	}
	file_state = fclose(stream);
	if(file_state==EOF)
		printf("파일 닫기 애러 \n");

}
void flip(int arr[],int c) {
	int mc,max,count=1;
	int f[30];
	int i,j;
	printf("Input data :");
	for (i = 0; i < c; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (j = c; j > 0;j--) {
		//find the biggest number each flip. if have same number,the biggest number is last one.
		for (i = 0; i < j; i++) {
			if (i == 0) {
				max = arr[i];
				mc = i;
			}
			if (arr[i] >= max) {
				max = arr[i];
				mc = i;
			}
		}
		//if the biggest number stand bottom already, skip the flip.
		if ((mc == j-1)) {
			
			continue;
		}
		//flip and print result.
		for (i = 0; i <= mc;i++) {
			f[i] = arr[i];
		}
		for (i = 0; i <= mc; i++) {
			arr[i]=f[mc-i];
		}
		printf("flip %d (%d) :  ", count, c - mc);
		for (i = 0; i < c; i++) {
			printf("%d ", arr[i]);
		}
		for (i = 0; i <= j; i++) {
			f[i] = arr[i];
		}
		
		for (i = 0; i < j;i++) {
			arr[i] = f[j-i-1];
		}
		printf("  ");
		for (i = 0; i < c; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		count++;
	}
	
}