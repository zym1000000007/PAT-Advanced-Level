#include <stdio.h>

const int max=123456789;

int* find(int x,int *b,int n) {
	int i = (n-1)/2;
	int *p=NULL;
	if (n > 0) {
		if (n > 1) {
			if (b[i] < x) {
				p = find(x,&b[i+1],n-i-1);
			} else if (b[i] >= x) {
				p = find(x,b,i+1);
			}
		} else {
			if (b[0] >= x) {
				p = &b[0];
			}
		}
	}
	return p;
}

int main(void) {
	int i,j,n,m,min,cnt,x,y;
	int *p;

	scanf("%d%d",&n,&m);
	int a[n+1],b[n+1],plan[n+1][2];

	b[0] = 0;
	for (i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		b[i] = b[i-1] + a[i];
	}
	min = max;
	cnt = 0;
	for (i=1; i<=n; i++) {
		p = find(b[i-1]+m,&b[i],n-i+1);
		if (p) {
			x = i;
			y = p-&b[0];
			if (b[y] - b[x-1] < min) {
				min = b[y] - b[x-1];
				plan[0][0] = x;
				plan[0][1] = y;
				cnt = 1;
//				printf("i=0 %d-%d\n",plan[0][0],plan[0][1]);
			} else if (b[y] - b[x-1] == min) {
				plan[cnt][0] = x;
				plan[cnt++][1] = y;
//				printf("cnt=%d %d-%d\n",cnt-1,plan[cnt-1][0],plan[cnt-1][1]);
			}
//			printf("%d-%d\n",x,y);
		}
	}
//	printf("cnt=%d\n",cnt);
	for (i=0; i<cnt; i++) {
		printf("%d-%d\n",plan[i][0],plan[i][1]);
	}

	return 0;
}
