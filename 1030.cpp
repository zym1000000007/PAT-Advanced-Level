#include<stdio.h>
#include<stdlib.h>
#define max 1000000000

int path[500][500],PATH[500];

int main() {
	int f,en,i,j,k,m,n,l1,F,min;
	int x,y,z,u;

	scanf("%d%d%d%d",&n,&m,&f,&en);
	int number;
	int d[n][n],d2[n][n],p[n],dis[n],dis2[n],book[n];

	for(i=0; i<n; i++)
		for(j=0; j<n; j++) {
			d[i][j]=max;
			path[i][j]=j;
			d2[i][j]=max;
//			if (i == j) {
//				d[i][j]=0;
//			}
		}

	for(i=0; i<m; i++) {
		scanf("%d%d%d%d",&x,&y,&z,&u);
		d[x][y]=z;
		d[y][x]=z;
		d2[x][y]=u;
		d2[y][x]=u;
	}

	for (i=0; i<n; i++) {
		book[i] = 0;
		dis[i] = d[f][i];
		dis2[i] = d2[f][i];
		PATH[i] = f;
	}

	book[f] = 1;
	for (i=0; i<n-1; i++) {
		min = max;
		u = -1;
		for (j=0; j<n; j++) {
			if ((book[j] == 0) && (dis[j] < min)) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (j=0; j<n; j++) {
			if ((j != f) && (j != u) && (d[u][j] < max)) {
				if (dis[u] + d[u][j] < dis[j]) {
					dis[j] = dis[u] + d[u][j];
					dis2[j] = dis2[u] + d2[u][j];
					PATH[j] = u;
				} else if (dis[u] + d[u][j] == dis[j]) {
					if (dis2[u] + d2[u][j] < dis2[j]) {
						dis2[j] = dis2[u] + d2[u][j];
						PATH[j] = u;
					}
				}
			}
		}
//		printf("u=%d\n",u);
//		for (j=0; j<n; j++) {
//			printf("j=%d dis=%d\n",j,dis[j]);
//		}
	}

	i = 1;
	p[0] = en;
	while (f!=p[i-1]) {
		p[i] = PATH[p[i-1]];
		i++;
	}
	k = i;
	for (i=k-1; i>=0; i--) {
		printf("%d ",p[i]);
	}

//	F=f;
//	while (f!=en) {
//		printf("%d",f);
//		printf(" ");
//		f=path[f][en];
//	}
	printf("%d %d",dis[en],dis2[en]);

	return 0;
}
