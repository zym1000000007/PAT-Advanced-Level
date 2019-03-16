#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b) {
	return *(int*)a - *(int*)b;
}

int* quchong(int *a,int n,int *m) {
	int *b = (int*)malloc(n*sizeof(int));
	int i,j=0,last=-1;
	for (i=0; i<n; i++) {
		if (last != a[i]) {
			b[j] = a[i];
			last = a[i];
			j++;
		}
	}
	*m = j;
	return b;
}

int main(void) {
	int i,j,n,m,x,y,z,K;

	scanf("%d",&n);
	int *a[n],num[n],*b[n],num2[n],*c,*C;

	for (i=0; i<n; i++) {
		scanf("%d",&m);
		num[i] = m;
		a[i] = (int*)malloc(m*sizeof(int));
		for (j=0; j<m; j++) {
			scanf("%d",&a[i][j]);
		}
	}

	for (i=0; i<n; i++) {
		qsort(a[i],num[i],sizeof(a[i][0]),cmp);
		b[i] = quchong(a[i],num[i],&num2[i]);
	}
//	for (i=0;i<n;i++) {
//		for (j=0;j<num2[i];j++) {
//			printf("%d ",b[i][j]);
//		}
//		printf("\n");
//	}

	scanf("%d",&K);
	for (i=0; i<K; i++) {
//		if (i > 0) {
//			printf("\n");
//		}
		scanf("%d%d",&x,&y);
		x--;
		y--;
		c = (int*)malloc((num2[x]+num2[y])*sizeof(int));
		for (j=0; j<num2[x]; j++) {
			c[j] = b[x][j];
		}
		for (j=0; j<num2[y]; j++) {
			c[num2[x]+j] = b[y][j];
		}
		qsort(c,num2[x]+num2[y],sizeof(c[0]),cmp);
		C = quchong(c,num2[x]+num2[y],&z);
		printf("%.1f%%\n",(num2[x]+num2[y]-z)*100.0/z);
		free(c);
	}

	return 0;
}
