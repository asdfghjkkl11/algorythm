
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

struct point {
	float x;
	float y;
};
struct point p[100];

struct point a = {0};
struct stack {
	struct point s;
}heap[100];
int count;
void main() {
	FILE* stream;
	int file_state;	
	int c1,c2,i,j,k,mi=0;
	int ccw(struct point , struct point, struct point);
	void push(struct point);
	void pop();
	void sort(int,int);
	float line;
	//file I/O
	stream = fopen("CC.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	//get try number
	fscanf(stream,"%d",&c1);
	for (i = 0; i < c1;i++) {
		count = 0;
		line = 2;
		//get floshs number
		fscanf(stream, "%d", &c2);
		for (j = 0; j < c2; j++) {
			//get dots finding most southern dot
			fscanf(stream, "%f %f", &p[j].x, &p[j].y);
			if (p[j].y == p[mi].y) {
				if (p[j].x < p[mi].x)
					mi = j;
			}
			if (p[j].y < p[mi].y) {
				mi = j;
			}
		}
		//sorting by east to west using cos
		sort(mi,c2);
		//push 3dots
		push(a);
		push(p[0]);
		push(p[1]);
		//push using grahms alogorithm 
		for (j = 2; j <c2; j++) {
				if (ccw(heap[j - 1].s, heap[j].s, p[j]) > 0) {
					push(p[j]);
				}
				else {
					pop();
					push(p[j]);
				}
		}
		//calculate silk length
		for (j = 1; j < count;j++) {
			line =line+ sqrt(pow(heap[j].s.x- heap[j - 1].s.x,2)+pow(heap[j].s.y- heap[j - 1].s.y,2));
			printf("%.2f\n", line);
		}
		line = line + sqrt(pow(heap[0].s.x, 2) + pow(heap[0].s.y, 2) + pow(heap[count - 1].s.x, 2) + pow(heap[count - 1].s.y, 2));
		printf("%.2f\n",line);
	}

	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
}
//sort by cos(angle) 
void sort(int mi,int c2) {
	int i,j;
	float cos[100];
	float temp;
	struct point t[100];
	t[0] = p[mi];
	p[mi] = p[0];
	p[0] = t[0];
	for (i = 1; i < c2;i++) {
		cos[i] = (p[i].x - p[0].x)/sqrt(((p[i].x - p[0].x)*(p[i].x - p[0].x) )+ ((p[i].y - p[0].y)*(p[i].y - p[0].y)));
	}
	for (i = 1; i < c2; i++) {
		for (j = 1; j < c2; j++) {
			if (cos[j] < cos[i]) {
				t[0] = p[i];
				p[i] = p[j];
				p[j] = t[0];
				temp = cos[i];
				cos[i] = cos[j];
				cos[j] = temp;
			}
		}
	}
}
//return about ccw, cw, parallel
int ccw(struct point p1, struct point p2, struct point p3) {
	float c = p1.x*p2.y - p2.x*p1.y + p2.x*p3.y - p3.x*p2.y + p3.x*p1.y - p1.x*p3.y;
	if(c>0)
		return 1;
	if(c<0)
		return -1;
	if(c==0)
		return 0;
}
//add dot to heap
void push(struct point a) {
	heap[count].s = a;
	count++;
}
//delete dot to heap
void pop() {
	count--;
}
