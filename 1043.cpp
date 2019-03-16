#include <stdio.h>

int yes;

void BST(int *a,int n,int *c) {
	int i,u;
	if (n > 1) {
		c[n-1] = a[0];
		for (i=1; i<n; i++) {
			if (a[i] >= a[0]) {
				break;
			}
		}
		u = i;
		for (i=u+1; i<n; i++) {
			if (a[i] < a[0]) {
				yes = 0;
				return;
			}
		}
		BST(&a[1],u-1,c);
		if (u < n)
			BST(&a[u],n-u,&c[u-1]);
	} else if (n == 1) {
		c[0] = a[0];
	}
}

void BST2(int *a,int n,int *c) {
	int i,u;
	if (n > 1) {
		c[n-1] = a[0];
		for (i=1; i<n; i++) {
			if (a[i] < a[0]) {
				break;
			}
		}
		u = i;
		for (i=u+1; i<n; i++) {
			if (a[i] >= a[0]) {
				yes = 0;
				return;
			}
		}
		BST2(&a[1],u-1,c);
		if (u < n)
			BST2(&a[u],n-u,&c[u-1]);
	} else if (n == 1) {
		c[0] = a[0];
	}
}

int main(void) {
	int i,j,n;

	scanf("%d",&n);
	int a[n],c[n];

	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	yes = 1;
	BST(a,n,c);
	if (yes == 0) {
		yes = 1;
		BST2(a,n,c);
	}
	if (yes) {
		printf("YES\n");
		for (i=0; i<n; i++) {
			if (i > 0) {
				printf(" ");
			}
			printf("%d",c[i]);
		}
	} else {
		printf("NO");
	}

	return 0;
}
