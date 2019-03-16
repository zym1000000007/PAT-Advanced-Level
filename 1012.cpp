#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int g[4],id,seq[4],min;
	char best;
} Node;

const int max=123456789;
int flag;

int cmp(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	return q->g[flag] - p->g[flag];
}

int cmp2(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	return p->id - q->id;
}

int main(void) {
	int i,j,n,m,id,x,y,z,last,lastseq;
	char classs[5] = {'A','C','M','E'};

	scanf("%d%d",&n,&m);
	Node node[n],*p,*q=(Node*)malloc(sizeof(Node));
	for (i=0; i<n; i++) {
		scanf("%d%d%d%d",&id,&x,&y,&z);
		node[i].id = id;
		node[i].g[1] = x;
		node[i].g[2] = y;
		node[i].g[3] = z;
		node[i].g[0] = (int)((x+y+z)/3.0 + 0.5);//四舍五入还是向下取整？
	}

	for (flag=0; flag<4; flag++) {
		qsort(node,n,sizeof(node[0]),cmp);
		last = -1;
		lastseq = -1;
		for (i=0; i<n; i++) {
			if (node[i].g[flag] == last) {
				node[i].seq[flag] = lastseq;
			} else {
				node[i].seq[flag] = i + 1;
				last = node[i].g[flag];
				lastseq = i + 1;
			}
		}
	}

	for (i=0; i<n; i++) {
		node[i].min = max;
		for (flag=0; flag<4; flag++) {
			if (node[i].seq[flag] < node[i].min) {
				node[i].min = node[i].seq[flag];
				node[i].best = classs[flag];
			}
		}
	}

	qsort(node,n,sizeof(node[0]),cmp2);
	for (i=0; i<m; i++) {
		if (i > 0) {
			printf("\n");
		}
		scanf("%d",&x);
		q->id = x;
		p = (Node*)bsearch(q,node,n,sizeof(node[0]),cmp2);
		if (p) {
			printf("%d %c",p->min,p->best);
		} else {
			printf("N/A");
		}
	}

	return 0;
}
