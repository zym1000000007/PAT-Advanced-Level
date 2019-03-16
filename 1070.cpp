#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node {
	double w,u;
	double p,P;
} Node;

int cmp(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	if (q->p - p->p > 0.000001) {
		return 1;
	} else if (q->p - p->p < -0.000001) {
		return -1;
	} else {
		return 0;
	}
//	return q->p - p->p;
}

int main(void) {
	int i,j,n;
	double m;
	double need;
	double profit;

	scanf("%d%lf",&n,&m);
	Node node[n];
//	int w[n];
//	double p[n],P[n],u[n];
	for (i=0; i<n; i++) {
		scanf("%lf",&node[i].w);
	}
	for (i=0; i<n; i++) {
		scanf("%lf",&node[i].P);
		node[i].p = node[i].P / node[i].w;
	}
	qsort(node,n,sizeof(node[0]),cmp);
//	for (i=0;i<n;i++) {
//		printf("%d %.2lf %.2lf\n",node[i].w,node[i].P,node[i].p);
//	}

	need = m;
	profit = 0;
	for (i=0; i<n; i++) {
		if (need > node[i].w) {
			node[i].u = node[i].w;
		} else {
			node[i].u = need;
		}
		profit += node[i].u/node[i].w*node[i].P;
//		printf("%d %.2lf %d %d %.2lf\n",need,profit,node[i].u,node[i].w,node[i].P);
		need -= node[i].u;
		if (abs(need) < 0.000001) {
			break;
		}
	}
	printf("%.2lf",profit);

	return 0;
}
