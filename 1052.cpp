#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int a,b,c;
} Node;

Node node1[123456],node[123456];

int cmp(const void *a,const void *b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	return p->b - q->b;
}

int main(void) {
	int i,m,n,a,b,c,j,k;

	scanf("%d%d",&n,&m);


	for (i=0; i<n; i++) {
		scanf("%d%d%d",&a,&b,&c);
//		node1[i].a = a;
		node1[a].b = b;
		node1[a].c = c;
	}

	if (m > -1) {
		k = node1[m].c;
		node[0].b = node1[m].b;
		node[0].a = m;
		j = 1;
		while (k != -1) {
			node[j].b = node1[k].b;
			node[j].a = k;
			j++;
			k = node1[k].c;
		}
		n = j;

		qsort(node,n,sizeof(node[0]),cmp);

		for (i=0; i<n-1; i++) {
			node[i].c = node[i+1].a;
		}
		node[n-1].c = -1;

		printf("%d %05d",n,node[0].a);
		for (i=0; i<n-1; i++) {
			printf("\n%05d %d %05d",node[i].a,node[i].b,node[i].c);
		}
		if (n-1 >= 0)
			printf("\n%05d %d %d",node[i].a,node[i].b,node[i].c);
	} else {
		printf("0 -1");
	}

	return 0;
}
