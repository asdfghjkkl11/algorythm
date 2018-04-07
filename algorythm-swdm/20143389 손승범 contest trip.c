//this program contest trip route.using input information, find the shortest route to destination.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct state {
	int s_time, d_time;
	char s_station[20], d_station[20];
	struct state * next;
}train[1000] = { 0 };
char s_start[20], s_end[20];
int c = 0,time;
int c1, c2, c3, c4;
struct station {
	char name[20];
	int weight;
}S[100];
void main() {
	FILE* stream;
	int file_state;	
	int i, j, k;
	char trans[5],z='0';
	void trip(int);
	struct state *find(); 
	struct state *t = (struct state*)malloc(sizeof(struct state));
	//file I/O
	stream = fopen("contest.txt", "r");
	if (stream == NULL)
		printf("파일 열기 애러 \n");
	//make-set
	fscanf(stream,"%d",&c1);
	for (i = 0; i < c1; i++) {
		c = 0;
		fscanf(stream, "%d", &c2);
		for (j = 0; j < c2; j++) {
			fscanf(stream, "%s", &S[j].name);
		}
		fscanf(stream, "%d", &c3);
		for (j = 0; j < c3; j++) {
			fscanf(stream, "%d", &c4);
			fscanf(stream, "%d %s", &train[c].s_time, &train[c].s_station);
			fscanf(stream, "%d %s", &train[c].d_time, &train[c].d_station);
			c++;
			if (c4 > 2) {
				for (k = 2; k < c4; k++) {
					train[c].s_time = train[c - 1].d_time;
					strcpy(train[c].s_station, train[c - 1].d_station);
					fscanf(stream, "%d %s", &train[c].d_time, &train[c].d_station);
					c++;
				}
			}

		}
		fscanf(stream, "%d", &time);
		fscanf(stream, "%s", &s_start);
		fscanf(stream, "%s", &s_end);
		//find-set to function
		trip(0);

		t = find();
		//print result
		//trans itoa to print time set 0000.
		itoa(t->s_time, trans, 10);

		if (strlen(trans) == 3) {
			printf("Departure   %c%s  %s\n", z, trans, t->s_station);
		}
		else {
			printf("Departure   %s  %s\n", trans, t->s_station);
		}
		while (t->next != NULL) {
			t = t->next;
		}
		itoa(t->d_time, trans, 10);

		if (strlen(trans) == 3) {
			printf("Arrival     %c%s  %s\n", z, trans, t->d_station);
		}
		else {
			printf("Arrival     %s  %s\n", trans, t->d_station);
		}
	}
	file_state = fclose(stream);
	if (file_state == EOF)
		printf("파일 닫기 애러 \n");
	
}
//this function make route to link each station the shortest time to destination.
void trip(int m) {
	int i,j,mi;
	int min;
	if (m == c2)
		return;
	for (i = 0; i < c;i++) {
		mi = 0;
		min = 0;
		if (strcmp(train[i].s_station , S[m].name)==0){
			for (j = 0; j < c; j++) {
				if ((strcmp(train[i].d_station , train[j].s_station)==0) && (train[i].d_time < train[j].s_time)) {
					if (min == 0) {
						mi = j;
						min = train[j].d_time;
					}
					else if (train[j].d_time < min) {
						mi = j;
						min = train[j].d_time;
					}
				}
			}
			if(mi!=0)
				train[i].next = &train[mi];
		}

	}
	trip(m + 1);
}
//this function find the shortest route. if routes take same time to destination, select the lastest start from start point.
struct state *find() {
	int i,s[100],d[100],r[100],mi=0;
	struct state *m=(struct state*)malloc(sizeof(struct state));
	for (i = 0; i < c; i++) {
		if ((strcmp(train[i].s_station, s_start) == 0) && (train[i].s_time > time)){
			m = &train[i];
			s[i] = m->s_time;
			while (m->next != NULL || (strcmp(train[i].s_station, s_end) == 0)) {
				if (m != 0) {
					m = m->next;
				}
			}
			d[i] = m->d_time;
			r[i] = d[i] - s[i];
		}
	}
	for (i = 0; i < c;i++) {
		if (d[i] == d[mi]) 
			if (s[i] > s[mi])
				mi = i;
		else if (d[i]<d[mi]) 
			mi = i;
	}
	if (m==NULL) {
		exit(1);
	}
	return &train[mi];
}

