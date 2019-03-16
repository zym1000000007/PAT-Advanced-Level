#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int id,w,seq,rank,round;
} Node;

int g;

void CMP(Node **node,int n,int round) {
	if (n > 1) {
		Node **no = (Node**)malloc(n*sizeof(Node*));
		int cnt=0,max,u,i,j;
//		for (i=0;i<n;i++) {
//			printf("%d ",node[i]->w);
//		}
//		printf("\n");
		for (i=0; i<n; i+=g) {
			max = 0;
			for (j=i; j<i+g && j < n; j++) {
				if (node[j]->w > max) {
					max = node[j]->w;
					u = j;
				}
			}
			for (j=i; j<i+g && j < n; j++) {
				if (j != u) {
					node[j]->round = round;
				} else {
//					printf("??\n");
					no[cnt++] = node[j];
//					printf("???\n");
				}
			}
		}
//		for (i=0;i<n;i++) {
//			printf("id=%d w=%d round=%d\n",node[i]->id,node[i]->w,node[i]->round);
//		}
		CMP(no,cnt,round+1);
	} else {
		node[0]->round = round;
	}
}

int cmp(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	return q->round - p->round;
}

int cmp2(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	return p->id - q->id;
}

int main(void) {
	int i,j,n,x,last,lastr;

	scanf("%d%d",&n,&g);
	Node node[n],*no[n];
	for (i=0; i<n; i++) {
		scanf("%d",&x);
		node[i].w = x;
		node[i].id = i;
	}
	for (i=0; i<n; i++) {
		scanf("%d",&x);
		node[i].seq = x;
		no[i] = &node[x];
//		printf("?\n");
	}
	CMP(no,n,1);
	qsort(node,n,sizeof(node[0]),cmp);
	lastr = 0;
	last = 0;
	for (i=0; i<n; i++) {
		if (node[i].round != lastr) {
			node[i].rank = i+1;
			lastr = node[i].round;
			last = i+1;
		} else {
			node[i].rank = last;
		}
	}
	qsort(node,n,sizeof(node[0]),cmp2);
	for (i=0; i<n; i++) {
		if (i > 0) {
			printf(" ");
		}
//		printf("id=%d round=%d rank=%d\n",node[i].id,node[i].round,node[i].rank);
		printf("%d",node[i].rank);
	}

	return 0;
}
