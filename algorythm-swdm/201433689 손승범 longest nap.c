#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	 this program calculate the best nap time among daily work. 
	first, gets data form text file to string. and time datas change int type.
	second, calculates the longest term bitween each scheduel. 
	third, changes minute data to char type again to show up hh:mm type.
	fourth, prints information the best nap time today to each condition.
*/
void main() {
	FILE* stream;
	int file_state;
	int day=0,i,j,s,max,maxi,ptr=0;
	char str[100][255];
	char starthh[100][2], startmm[100][2], endhh[100][2], endmm[100][2],mm[3]; 
	int starthh2[100], startmm2[100], endhh2[100], endmm2[100];
	int sumh[100],summ[100],sum[100];
	stream = fopen("nap.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	//the program running while end of file.
	while (!feof(stream)) {
		fscanf(stream, "%d", &s);
		fscanf(stream, "\n");
		day++;
		ptr++;
		//gets data form text file to string. and time datas change int type.
		for (i = ptr; i < ptr + s; i++) {
			fgets(str[i], sizeof(str[i]), stream);
			for (j = 0; j < 2; j++) {
				starthh[i][j] = str[i][j];
				startmm[i][j] = str[i][j + 3];
				endhh[i][j] = str[i][j + 6];
				endmm[i][j] = str[i][j + 9];
			}
			starthh[i][j] = 0;
			endhh[i][j] = 0;
			startmm[i][j] = 0;
			endmm[i][j] = 0;
			starthh2[i] = atoi(starthh[i]);
			endhh2[i] = atoi(endhh[i]);
			startmm2[i] = atoi(startmm[i]);
			endmm2[i] = atoi(endmm[i]);
		}
		//calculates the longest term bitween each scheduel.
		max = 0;
		maxi = 0;
		for (i = ptr; i < ptr + s; i++)
		{
			sumh[i] = starthh2[i + 1] - endhh2[i];
			summ[i] = startmm2[i + 1] - endmm2[i];
			if (summ[i] < 0) {
				summ[i] = summ[i] + 60;
				sumh[i] = sumh[i] - 1;
			}
			sum[i] = summ[i] + (sumh[i] * 60);
			if (summ[i] > max) {
				max = sum[i];
				maxi = i;
			}
			if (maxi == 0)
				maxi = i;
		}
		ptr += s;
		//changes minute data to char type again to show up hh:mm type.
		itoa(endmm2[maxi], mm, 2);
		if (strlen(mm) == 1) {
			mm[2] = 0;
			mm[1] = mm[0];
			mm[0] = '0';
		}
		//prints information the best nap time today to each condition.
		if (sumh[maxi] == 0)
			printf("Day #%d:the longest nap starts at %d:%s and will last for %d minutes. \n", day, endhh2[maxi], mm, summ[maxi]);
		else if ((max == 0) || (s == 1))
			printf("Day #%d:today scheduel ends at %d:%s has not break time. \n",day, endhh2[maxi], mm);
		else
			printf("Day #%d:the longest nap starts at %d:%s and will last for %d hours and %d minutes. \n", day,endhh2[maxi], mm, sumh[maxi], summ[maxi]);
	}
	file_state = fclose(stream);
	if(file_state==EOF)
		printf("파일 닫기 애러 \n");

}