#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void*a,const void*b) {
	return *(int*)b - *(int*)a;
}

int main(void) {
	int i,j,n,n1,n2;
	int a[4],b[4];

	scanf("%d",&n);

	do {
		for (i=0; i<4; i++) {
			a[i] = n / (int)pow(10,3-i);
			n = n % (int)pow(10,3-i);
//		printf("%d ",a[i]);
		}
		qsort(a,4,sizeof(a[0]),cmp);
		n1 = 0;
		n2 = 0;
		for (i=0; i<4; i++) {
			b[i] = a[3-i];
			n2 += b[i] * (int)pow(10,3-i);
			n1 += a[i] * (int)pow(10,3-i);
//		printf("%d %d\n",a[i],b[i]);
		}
		n = n1 - n2;
		printf("%04d - %04d = %04d\n",n1,n2,n);
		if (n == 0) {
			break;
		}
	} while (n != 6174);

	return 0;
}
