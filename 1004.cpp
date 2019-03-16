#include <stdio.h>

typedef struct _Node {
	int index,cnt,level;
	struct _Node *next[100];
} Node;

int L[100],M;

void BFS(Node* root) {
	int i,j,end;
	Node *a[100],*p;
	if (root) {
		i = 0;
		a[i] = root;
		end = 1;
		while (a[i]) {
//			printf("i=%d\n",i);
			p = a[i];
			M = p->level;
			if (p->cnt == 0) {
				L[p->level]++;
			}
			for (j=0; j<p->cnt; j++) {
				a[end] = p->next[j];
				a[end]->level = p->level + 1;
				end++;
			}

			i++;
			if (i >= end) {
				break;
			}
		}
	}
}

int main(void) {
	int i,j,n,m,x,y,k;

	scanf("%d%d",&n,&m);
	Node node[n+1];
	for (i=0; i<=n; i++) {
		node[i].index = i;
		node[i].cnt = 0;
	}
	for (i=0; i<m; i++) {
		scanf("%d%d",&x,&k);
		for (j=0; j<k; j++) {
			scanf("%d",&y);
			node[x].next[node[x].cnt] = &node[y];
			node[x].cnt++;
		}
	}
	node[1].level = 0;
	BFS(&node[1]);
	for (i=0; i<=M; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d",L[i]);
	}

	return 0;
}
