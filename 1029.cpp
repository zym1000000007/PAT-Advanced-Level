#include <stdio.h>
#include <stdlib.h>
//#define max 0x7ffffff
#define max 2100000000


int main(void) {
	long int b,median;
	int n,m,i,j,med,l=1;

	scanf("%d",&n);
	int a[n+1];
	for (i=0; i<n; i++) {
		scanf("%d",&(a[i]));
	}
	a[n]=max;
	scanf("%d",&m);
//	p=&(a[0]);
	med = (n+m+1)/2;
//	q=(long long int*)malloc(sizeof(long long int));
	scanf("%ld",&b);
	j=0;
	for (i=0; i<med; i++) {
//		A = (long long int)(a[j]);
		if (a[j]< b) {
			median = a[j];
			j++;
		} else {
			median = b;
//			free(q);
//			q=(long long int*)malloc(sizeof(long long int));
			if (l<m) {
				scanf("%ld",&b);
				l++;
			} else {
				b=max;
			}
		}
	}

	printf("%ld",median);

	return 0;
}
