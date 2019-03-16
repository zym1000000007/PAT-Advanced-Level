#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node {
	int index,key;
	struct _Node *left,*right;
} Node;

int num[1000],I;

int cmp(const void*a,const void*b) {
	return *(int*)a - *(int*)b;
}

void inorder(Node *root) {
	if (root) {
		inorder(root->left);
		root->key = num[I];
		I++;
		inorder(root->right);
	}
}

int main(void) {
	int i,j,n;

	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&num[i]);
	}
	qsort(num,n,sizeof(num[0]),cmp);
	Node node[n+1],*a[n],*root;
	for (i=1; i<=n; i++) {
		node[i].index = i;
	}

	for (i=1; i<=n; i++) {
		if (i*2 > n) {
			node[i].left = NULL;
		} else {
			node[i].left = &node[i*2];
		}
		if (i*2+1 > n) {
			node[i].right = NULL;
		} else {
			node[i].right = &node[i*2+1];
		}
	}

//	a[0] = &node[1];
//	i = 1;
//	j = 0;
//	do {
//		root = a[j];
////		printf("root=%d\n",root->index);
//		j++;
//		a[i++] = root->left;
//		a[i++] = root->right;
//	} while (i < n);

	inorder(&node[1]);
	for (i=1; i<=n; i++) {
		if (i > 1) {
			printf(" ");
		}
		printf("%d",node[i].key);
	}

	return 0;
}
