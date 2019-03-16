#include<stdio.h>
#include<stdlib.h>
#define max 1234567890

int Max(int i,int j);

int main() {
	int f,en,i,j,m,n,u,min;
	int x,y,z;

	scanf("%d%d%d%d",&n,&m,&f,&en);
	int number,N[n];
	int d[n][n],team1[n],team2[n][n],book[n],dis[n];

	for(i=0; i<n; i++) {
		scanf("%d",&team1[i]);
	}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++) {
			d[i][j]=max;
			N[i]=0;
			if (i == j) {
				d[i][j]=0;
				//N[i]=1;//¦Ì¨²?t??2a¨º?¦Ì?¨º?¡Á??o¦Ì?¡Á??o¦Ì?
				team2[i][j]=team1[i];
			} else {
				team2[i][j]=team1[i]+team1[j];
			}
		}
	N[f]=1;

	for(i=0; i<m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		d[x][y]=z;
		d[y][x]=z;
		if (x == f) {
			N[y] = 1;
		} else if (y == f) {
			N[x] = 1;
		}
	}
	for (i=0; i<n; i++) {
		book[i] = 0;
		dis[i] = d[f][i];
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
		if ((u < 0) || (u >= n)) {
			break;
		}
		book[u] = 1;
		for (j=0; j<n; j++) {
			if ((j != f) && (j != u) && (dis[u] < max)) {//?D???a¨¤??¨®???D??¡À¨¨?¡À?¨®d[i][i]=0o?¡ê?¨°¨°?a?¨¦?¨¹?¨¢D¨¨¨°a¡Á??o¦Ì?¡Á??o¦Ì??¨¦??¡ê???¨¨??a?¨´?¨¢?t¨¦¨¹?¨´?¨¨
				if (dis[u] + d[u][j] < dis[j]) {
					dis[j] = dis[u] + d[u][j];
					N[j] = N[u];
					team2[f][j] = team2[f][u] + team2[u][j] - team1[u];
				} else if (dis[u] + d[u][j] == dis[j]) {
					N[j] += N[u];
					team2[f][j] = Max(team2[f][j],team2[f][u] + team2[u][j] - team1[u]);
				}
			}
		}
//		printf("u=%d N=%d\n",u,N[f][en]);
//		for (j=0;j<n;j++) {
//			printf("j=%d dis=%d\n",j,dis[j]);
//		}
	}

	number = N[en];
	printf("%d %d",number,team2[f][en]);

	return 0;
}

int Max(int i,int j) {
	int MAX=i;
	if (i<j)
		MAX=j;
	return MAX;
}
