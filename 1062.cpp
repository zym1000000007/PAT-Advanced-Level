#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int ID,v,t,type,all;
} Node;

int cmp(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	if (p->type != q->type) {
		return p->type - q->type;
	} else if (p->all != q->all) {
		return q->all - p->all;
	} else if (p->v != q->v) {
		return q->v - p->v;
	} else {
		return p->ID - q->ID;
	}
}

int main(void) {
	int i,j,n,m,L,H,x,y,z;

	scanf("%d%d%d",&n,&L,&H);
	Node node[n];

	m = n;
	for (i=0; i<n; i++) {
		scanf("%d%d%d",&x,&y,&z);
		node[i].ID = x;
		node[i].v = y;
		node[i].t = z;
		node[i].all = y + z;
		if ((y >= H) && (z >= H)) {
			node[i].type = 0;
		} else if ((y < L) || (z < L)) {
			node[i].type = 4;
			m--;
		} else if ((y >= H) && (z < H)) {
			node[i].type = 1;
		} else if ((y < H) && (z < H) && (y >= z)) {
			node[i].type = 2;
		} else if ((y < H) && (z > y)) {
			node[i].type = 3;
		}
	}

	qsort(node,n,sizeof(node[0]),cmp);

	printf("%d",m);
	for (i=0; i<m; i++) {
		printf("\n%d %d %d",node[i].ID,node[i].v,node[i].t);
	}

	return 0;
}
