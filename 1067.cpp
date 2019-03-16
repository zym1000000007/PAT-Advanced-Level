#include <stdio.h>

int main(void) {
	int i,j,n,t,step,x,y,yes,cnt=0,k;

	scanf("%d",&n);
	int a[n],b[n],c[n];
	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
		b[a[i]] = i;
	}
	for (i=0; i<n; i++) {
		if (a[i] != i) {
			c[cnt++] = i;
		}
	}
	yes = 1;
	step = 0;
	k = 0;
	while (yes) {
		while (a[0] != 0) {
//			x = find(a,0,n);
//			y = find(a,x,n);
			x = b[0];
			y = b[x];
			a[x] = x;
			a[y] = 0;
			b[x] = x;
			b[0] = y;
			step++;
//		printf("x=%d y=%d\n",x,y);
		}
		for (j=k; j<cnt; j++) {
			i = c[j];
			if (a[i] != i) {
				x = a[i];
				a[0] = x;
				a[i] = 0;
				b[x] = 0;
				b[0] = i;
				k = j + 1;
				step++;
				break;
			}
		}
		yes = 0;
		for (i=0; i<n; i++) {
			if (a[i] != i) {
				yes = 1;
				break;
			}
		}
	}

	printf("%d",step);

	return 0;
}
