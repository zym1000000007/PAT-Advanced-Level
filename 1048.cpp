#include <stdio.h>
#include <stdlib.h>
#define max 123456789

int cmp(const void *a,const void *b) {
	return (*(int*)a - *(int*)b);
}

int main(void) {
	int i,j,n,pay,k,yes=0,last;
	int *p;

	scanf("%d%d",&n,&pay);
	int value[n+1];

	for (i=0; i<n; i++) {
		scanf("%d",&value[i]);
	}
	value[n] = max;

	qsort(value,n,sizeof(value[0]),cmp);
	last = 0;
	for (i=0; i<n; i++) {
		if (value[i] != last) {
			last = value[i];
			k = pay - value[i];
			value[i] = value[i+1];
			p = (int*)bsearch(&(k),value,n,sizeof(value[0]),cmp);
			value[i] = pay - k;
			if (p) {
				printf("%d %d",value[i],*p);
				yes = 1;
				break;
			}
		}
	}
	if (!yes) {
		printf("No Solution");
	}

	return 0;
}
