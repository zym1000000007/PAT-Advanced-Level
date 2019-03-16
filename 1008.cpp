#include <stdio.h>

int main(void) {
	int n,i,time=0,last=0;

	scanf("%d",&n);
	int a[n];

	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
		if (a[i]>last) {
			time = time + 6*(a[i]-last) + 5;
		} else if (a[i]<last) {
			time = time + 4*(last-a[i]) + 5;
		} else {
			time = time + 5;
		}
		last = a[i];
//		printf("a[i]=%d\n",a[i]);
	}
	printf("%d",time);

	return 0;
}
