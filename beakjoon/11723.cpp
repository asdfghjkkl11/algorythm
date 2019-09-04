#include <iostream>
#include <cstring>
using namespace std;
int cache, N, a, M = 2097151;
char str[10];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		if (strcmp(str, "all") == 0)
			cache = M;
		else if (strcmp(str, "empty") == 0)
			cache = 0;
		else {
			scanf("%d", &a);
			if (strcmp(str, "add") == 0)
				cache = cache | (1 << a);
			else if (strcmp(str, "remove") == 0)
				cache = cache&(M ^ (1 << a));
			else if (strcmp(str, "check") == 0)
				if (cache&(1 << a))
					printf("1\n");
				else
					printf("0\n");
			else if (strcmp(str, "toggle") == 0)
				cache = cache ^ (1 << a);
		}
	}
	return 0;
}
