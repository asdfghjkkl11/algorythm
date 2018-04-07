
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

struct point {
	float x;
	float y;
};
struct point p[30];
int count;
void main() {
	FILE* stream;
	int file_state;
	int i, j, k;
	float BF(int, int);
	float CP(int, int);
	float d;
	//file I/O
	stream = fopen("MS.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	fscanf(stream, "%d", &k);
	for (j = 0; j < k; j++) {
		fscanf(stream, "%d", &count);
		for (i = 0; i < count; i++) {
			fscanf(stream, "%f %f", &p[i].x, &p[i].y);
		}
		d = CP(0, count);
		if (d>10000) {
			printf("infinite\n");
		}
		printf("%.2f\n", d);
	}
	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
}
//closest-pair problem
float CP(int a, int b) {
	struct point s[30], t;
	float R, L, d, q;
	int i, j, c = 0;
	if (b - a<3) {
		return BF(a, b);
	}
	//find shortesy distnace of between dots right one left one
	q = a + b / 2;
	L = CP(a, q - 1);
	R = CP(q, b);
	if (L > R)
		d = R;
	else
		d = L;
	//combining two solution
	for (i = a; i < b; i++) {
		if (p[a].x - d <= p[i].x&&p[i].x <= p[a].x + d) {
			s[c] = p[i];
			c++;
		}
	}
	for (i = 0; i < c; i++) {
		for (j = i; j < c; j++) {
			if (s[j].y<s[i].y) {
				t = s[j];
				s[j] = s[i];
				s[i] = t;
			}
		}
	}
	for (i = 0; i < c; i++) {
		for (j = i + 1; j<i + 8; j++) {
			if (j + 1 == c || i == c - 1)
				break;
			if (sqrt(pow(s[i].x - s[j].x, 2) + pow(s[i].y - s[j].y, 2)) < d)
				d = sqrt(pow(s[i].x - s[j].x, 2) + pow(s[i].y - s[j].y, 2));
		}
	}
	return d;
}
//brute force algorithm
float BF(int a, int b) {
	int i, j;
	float min = 10000, d = 0;
	for (i = a; i < b; i++) {
		for (j = i + 1; j <= b; j++) {
			d = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));

			if (d < min)
				min = d;

		}
	}
	return min;
}