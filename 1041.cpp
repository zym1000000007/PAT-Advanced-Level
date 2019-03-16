#include <stdio.h>

const int size=10001;

typedef struct _Node {
	int num,seq;
} Node;

int main(void) {
	int i,j,n,win,first,d;

	scanf("%d",&n);
	Node node[size];

	for (i=0; i<size; i++) {
		node[i].num=0;
	}
	j=0;
	for (i=0; i<n; i++) {
		scanf("%d",&d);
		node[d].num++;
		node[d].seq = i;
		j++;
	}
	n=j;

	first = 1000001;
	win = -1;
	for (i=0; i<size; i++) {
//		if (node[i].num > 0) {
////			printf("i=%d seq=%d num=%d\n",i,node[i].seq,node[i].num);
//		}
		if (node[i].num == 1) {
			if (node[i].seq < first) {
				win = i;
				first = node[i].seq;
			}
		}
	}

	if (win == -1) {
		printf("None");
	} else {
		printf("%d",win);
	}

	return 0;
}
