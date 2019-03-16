#include <stdio.h>
#include <stdlib.h>

int given,path2[123456][100],path[101],CNT;

typedef struct _Node {
	int weight,num,level,total;
	struct _Node **child;
} Node;

void deep(Node* root,int level) {
	int i,j;

//	printf("weight=%d num=%d level=%d\n",root->weight,root->num,level);
	path[level] = root->weight;
	root->level = level;
	if (root->num > 0) {
		for (i=0; i<root->num; i++) {
			root->child[i]->total = root->total + root->child[i]->weight;
			deep(root->child[i],level+1);
		}
	} else if (root->total == given) {
		for (j=1; j<=level; j++) {
			path2[CNT][j] = path[j];
//			printf("%d ",path[j]);
		}
		CNT++;
//		printf("\n");
	}
}

int cmp(const void* a,const void* b) {
	int *p = (int*)a;
	int *q = (int*)b;
	int i = 1,j;

//	for (j=0;j<4;j++) {
//		printf("p=%d q=%d\n",p[j],q[j]);
//	}
	while ((p[i] == q[i]) && (p[i] != 0) && (q[i] != 0)) {
		i++;
	}
//	printf("i=%d p=%d q=%d\n",i,p[i],q[i]);
	return q[i] - p[i];
}

int main(void) {
	int i,j,n,m,num,child,k,cnt;

	scanf("%d%d%d",&n,&m,&given);
	Node node[n];
	Node *root=&node[0];

	for (i=0; i<n; i++) {
		scanf("%d",&node[i].weight);
		node[i].num = 0;
		node[i].total = 0;
	}

	for (i=0; i<m; i++) {
		scanf("%d%d",&k,&num);
		node[k].num = num;
		node[k].child = (Node**)malloc(num * sizeof(Node*));
		cnt = 0;
		for (j=0; j<num; j++) {
			scanf("%d",&child);
			node[k].child[cnt] = &node[child];
			cnt++;
		}
	}

	root->total = root->weight;
	deep(root,1);

	qsort(path2,CNT,sizeof(path2[0]),cmp);

//	printf("CNT=%d\n",CNT);
	for (i=0; i<CNT; i++) {
		if (i > 0) {
			printf("\n");
		}
		j = 1;
		while (path2[i][j] != 0) {
			if (j > 1) {
				printf(" ");
			}
			printf("%d",path2[i][j]);
			j++;
		}
//		printf("\nj=%d size=%d\n",j,sizeof(path2[0]));
	}
//	for (i=0;i<n;i++) {
//		printf("i=%d level=%d\n",i,node[i].level);
//	}

	return 0;
}
