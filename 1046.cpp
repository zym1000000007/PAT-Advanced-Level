#include <stdio.h>
#define size 123456

int dis[size];

int _min(int a,int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

int main(void) {
	int i,j,n,m,min,sum,small,large,x,y;

	scanf("%d",&n);
	int d[n];

	for (i=0; i<n; i++) {
		scanf("%d",&(d[i]));
	}

	scanf("%d",&m);
	int road[m][2];

	for (i=0; i<m; i++) {
		scanf("%d%d",&(road[i][0]),&(road[i][1]));
		road[i][0]--;
		road[i][1]--;
	}

	for (i=0; i<n; i++) {
		dis[i] = 0;
	}

	i=0;
	for (j=1; j<n; j++) {
		dis[j] = dis[j-1] + d[j-1];
	}
	sum = dis[n-1] + d[n-1];

	for (i=0; i<m; i++) {
		if (i > 0) {
			printf("\n");
		}
		x = road[i][0];
		y = road[i][1];
		small = _min(x,y);
		large = x+y-small;
		min = _min(dis[large]-dis[small],sum - (dis[large] - dis[small]));
		printf("%d",min);
	}

	return 0;
}
