#include <stdio.h>
#include <math.h>
#define max 123456789

typedef struct _Node {
	int id,sent,back,pcnt,ncnt;
	int pre[501],next[501];
} Node;

//const int max = 123456789;
Node node[500+1];
int PATH[501],PATH2[501],en,CNT,Smin=max,Bmin=max;

int abs(int);

void DFS(Node *root,int level,int SENT,int BACK) {
	int i,yes,u;
	if (root) {
		PATH[level] = root->id;
		if (root->sent > BACK) {
			SENT = SENT + root->sent - BACK;
			BACK = 0;
		} else {
			BACK = BACK - root->sent + root->back;
		}
//        printf("id=%d S=%d B=%d\n",root->id,SENT,BACK);
		if (root->id == en) {
			yes = 0;
			if (SENT < Smin) {
				yes = 1;
			} else if ((SENT == Smin) && (BACK < Bmin)) {
				yes = 1;
			}
			if (yes) {
				Smin = SENT;
				Bmin = BACK;
				for (i=0; i<=level; i++) {
					PATH2[i] = PATH[i];
				}
				CNT = level+1;
			}
		} else {
//            printf("cnt=%d\n",root->)
			for (i=0; i<root->ncnt; i++) {
				u = root->next[i];
				DFS(&node[u],level+1,SENT,BACK);
			}
		}
	}
}

int main(void) {
	int i,j,n,Cmax,m,f,x,y,z,min,u;

	scanf("%d%d%d%d",&Cmax,&n,&en,&m);
	int d[n+1][n+1],dis[n+1],book[n+1];

	for (i=0; i<=n; i++) {
		for (j=0; j<=n; j++) {
			d[i][j] = max;
		}
	}
	for (i=0; i<=n; i++) {
		node[i].pcnt = 0;
		node[i].ncnt = 0;
		node[i].id = i;
	}
	f = 0;

	node[0].sent = 0;
	node[0].back = 0;
	for (i=1; i<=n; i++) {
		scanf("%d",&x);
		y = x - Cmax/2;
		node[i].sent = (abs(y)-y)/2;
		node[i].back = (abs(y)+y)/2;
//        printf("i=%d s=%d b=%d\n",i,node[i].sent,node[i].back);
	}
	for (i=0; i<m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		d[x][y] = z;
		d[y][x] = z;
	}
	for (i=1; i<=n; i++) {
		dis[i] = d[f][i];
		book[i] = 0;
		node[i].pre[0] = f;
		node[i].pcnt = 1;
	}
	dis[f] = d[f][f];
	book[f] = 1;
	for (i=0; i<n; i++) {
		min = max;
		u = -1;
		for (j=1; j<=n; j++) {
			if ((book[j] == 0) && (dis[j] < min)) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1) {
			break;
		}
		book[u] = 1;
		if (dis[u] < max) {
			for (j=1; j<=n; j++) {
				if (j != u) {
					if (dis[u] + d[u][j] < dis[j]) {
						dis[j] = dis[u] + d[u][j];
						node[j].pre[0] = u;
						node[j].pcnt = 1;
					} else if (dis[u] + d[u][j] == dis[j]) {
						node[j].pre[node[j].pcnt++] = u;
					}
				}
			}
		} else {
			break;
		}
	}
	for (i=0; i<=n; i++) {
		for (j=0; j<node[i].pcnt; j++) {
			u = node[i].pre[j];
			node[u].next[node[u].ncnt++] = i;
		}
	}
	DFS(&node[f],0,0,0);
	printf("%d %d",Smin,f);
	for (i=1; i<CNT; i++) {
		printf("->%d",PATH2[i]);
	}
	printf(" %d",Bmin);

	return 0;
}

