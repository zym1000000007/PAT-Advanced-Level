#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
	int i,j,n,one;
	char str[20];
	int sum;

	scanf("%s",str);
	n=strlen(str)-1;
//	printf("n=%d\n",n);
	int a[n+1],b[n+1];

	for (i=0; i<=n; i++) {
		a[i] = str[n-i] - '0';
//		printf("i=%d a=%d\n",i,a[i]);
	}
	b[-1]=0;
//	b[0] = 1;
	for (i=0; i<=n; i++) {
		b[i] = b[i-1]*10 + pow(10,i);
//		printf("i=%d %d\n",i,b[i]);
	}

	sum = 0;
	one = 0;
	for (i=n; i>=0; i--) {
		if (a[i] == 0) {
			sum += 0;
			sum += one*a[i]*pow(10,i);
		} else if (a[i] == 1) {
//			if (i > 0)
			sum += (a[i])*b[i-1] + 1;
//			else
//				sum += 1;
			sum += one*a[i]*pow(10,i);
			one++;
		} else if (a[i] > 1) {
//			if (i > 0)
			sum += (a[i])*b[i-1] + pow(10,i);
//			else
//				sum += pow(10,i);
			sum += one*a[i]*pow(10,i);
		}
//		printf("sum1=%d\n",sum);
//		printf("sum2=%d\n",sum);
	}
	printf("%d",sum);

	return 0;
}
