#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int b;
	int index;
} Node;

int cmp(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	if (p->b != q->b) {
		return p->b - q->b;
	} else {
		return q->index - p->index;
	}
}

int main(void) {
	int i,j,n,min,max,k1,k2,find,yes;

	scanf("%d",&n);
	int a[n],b[n+1];
	Node node[n+1];

	b[0] = 0;
	node[0].b = 0;
	yes = 0;
	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
		if (a[i] >= 0) {
			yes = 1;
		}
		b[i+1] = b[i] + a[i];
		node[i+1].b = node[i].b + a[i];
		node[i].index = i;
	}
	node[n].index = n;
	qsort(node,n+1,sizeof(node[0]),cmp);
	max = -123456789;
	for (i=0; i<n; i++) {
		find = 0;
		for (j=n; j>0; j--) {
			if (node[j].index > i) {
				find = 1;
				break;
			}
		}
//		if (find) {
//			printf("i=%d min=%d k2=%d max=%d\n",i,b[i],node[j].index,node[j].b);
		if (node[j].b - b[i] > max) {
			max = node[j].b - b[i];
			k2 = a[node[j].index-1];
			k1 = a[i];
		}
//		}
	}

	if (yes == 0) {
		max = 0;
		k1 = a[0];
		k2 = a[n-1];
	}
	printf("%d %d %d",max,k1,k2);

	return 0;
}
