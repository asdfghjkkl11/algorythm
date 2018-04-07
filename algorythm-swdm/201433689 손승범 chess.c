#include<stdio.h>
#include<stdlib.h>

int c=0;
void main() {
	FILE* stream;
	int file_state;
	int n, k, f;
	int matrix[10][10] = { 0 };
	int fact(int);
	void backtrack(int[][10], int, int);
	//file I/O
	stream = fopen("Chess.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	while (!feof(stream)) {
		fscanf(stream, "%d %d", &n, &k);
		if (n == 0 || k == 0)
			continue;
		c = 0;
		//backtracking algorithm
		backtrack(matrix, n, k);
		//remove duplicate k!
		f = fact(k);
		printf("%d\n", c / f);
	}
	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
}
int fact(int k) {
	//calculate factorial
	int f=1;
	while (k) {
		f = f*k;
		k--;
	}
	return f;
}
void backtrack(int matrix[][10],int n, int k) {
	int i,j,l,m,p,s=1;
	if (k==0) {
		c++;
		return;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			s = 1;
			for (l = 0; l < n;l++) {
				for (m = 0; m < n;m++) {
					if (matrix[l][m] != 0)
						if (i - l == j - m || i - l == -(j - m))
							//if bishop in range of other bishop, don't bother child node
							s = 0;
				}
			}
			//place bishop one space
			matrix[i][j] ++;
			p = k - 1;
			if(s==1)
			backtrack(matrix,n,p);
			//remove bisjop next process
			matrix[i][j] --;
		}
	}
	
}
