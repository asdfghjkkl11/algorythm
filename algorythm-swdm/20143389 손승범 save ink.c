/*
This program calculate the most efficient using ink. It saperated two part, make-set and find-set. 
make-set defines dots read from file, and calculate distance each dots. 
find-set finds the shortest distance and links dots if one dot has link already, ignore the dot.
Finally, print result sum of all distance of linked dots.
*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
void main() {
	FILE* stream;
	int file_state;	
	int c1,c2, i, j,k,link[30][30] = {0},x1,y1,count=0;
	float x[30], y[30],dis[30][30],min,result=0;
	stream = fopen("dot.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	fscanf(stream,"%d",&c1);
	for (k = 0; k < c1; k++) {
		fscanf(stream, "%d", &c2);
		//MAKE-SET
		for (i = 0; i < c2; i++) {
			fscanf(stream, "%f %f", &x[i], &y[i]);
		}
		for (i = 0; i < c2; i++) {
			for (j = 0; j < c2; j++) {
				dis[i][j] = sqrt(((x[j] - x[i])*(x[j] - x[i])) + ((y[j] - y[i])*(y[j] - y[i])));
			}
		}
		//FIND-SET
		while (count < c2) {
			x1 = 0;
			y1 = 0;
			min = 0;
			for (i = 0; i < c2; i++) {
				//if dot has link already, ignore the dot.
				for (j = 0; j < c2; j++) {
					if (link[i][j] == 1)
						break;
				}
				if (link[i][j] == 1)
					continue;
				for (j = 0; j < c2; j++) {
					if (min == 0) {
						min = dis[i][j];
						x1 = i;
						y1 = j;
					}
					else if (dis[i][j] < min) {
						min = dis[i][j];
						x1 = i;
						y1 = j;
					}
				}
			}
			//link dots have the shortest distance and plus result.
			result = result + min;
			link[x1][y1] = 1;
			link[y1][x1] = 1;
			count++;
		}
		printf("%d result: %.2f\n",k+1, result);
	}
	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
	
}

