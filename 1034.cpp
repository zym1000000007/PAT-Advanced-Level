#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int max=100000;
const int large=20000;

typedef struct _cluster {
	int time,member,max;
	char head[4];
} Cluster;

typedef struct _node {
	char name[4];
	int min,time,nodenum,childnum,group,level;
	struct _node **child;
} Node;

Node **node;
int index[2101];

void _group(Node*,int,int);
void namesort2(Cluster *bill,int n);

int main(void) {
	int i,j,k,n,m,time,GROUP,x,y,total;
	int road2[large][2];
	char name1[4],name2[4];
	Cluster cluster[2101];
	Cluster out[2101];
	node=(Node**)malloc(large*sizeof(Node*));

	scanf("%d%d",&m,&k);
	for (i=0; i<large; i++) {
		node[i] = (Node*)malloc(sizeof(Node));
		node[i]->time = 0;
		node[i]->nodenum = 0;
		node[i]->childnum = 0;
		node[i]->group = -1;
		node[i]->level = max;
	}

	for (i=0; i<m; i++) {//?¨¢¨¨?¨ºy?Y¡ê?¨ºy3??????¨²¦Ì?¨®D?????¨¤¨¢¨²?¨²¦Ì?
		scanf("%s%s%d",name1,name2,&time);
		x = (name1[0] - 'A')*26*26 + (name1[1] - 'A')*26 + (name1[2] - 'A');
		y = (name2[0] - 'A')*26*26 + (name2[1] - 'A')*26 + (name2[2] - 'A');
		road2[i][0]=x;
		road2[i][1]=y;
		strcpy(node[x]->name,name1);
		strcpy(node[y]->name,name2);
		node[x]->time += time;
		node[y]->time += time;
		node[x]->nodenum++;
		node[y]->nodenum++;
//		printf("x=%d y=%d %s %s\n",x,y,name1,name2);
	}
	j=0;
	for (i=0; i<large; i++) {
		if (node[i]->time > 0) {
			index[j] = i;
			j++;
		}
	}
	n=j;
//	for (i=0;i<n;i++) {
//		printf("name=%s time=%d group=%d nodenum=%d childnum=%d\n",node[index[i]]->name,node[index[i]]->time,node[index[i]]->group,node[index[i]]->nodenum,node[index[i]]->childnum);
//	}
//	printf("\n\n");

	for (i=0; i<n; i++) {
		node[index[i]]->child=(Node**)malloc(node[index[i]]->nodenum*sizeof(Node*));
	}
	for (i=0; i<m; i++) {//?¨´?Y¦Ì¨¤?¡¤?¡§¨¢¡é?¨²¦Ì??¨¤¨¢?1??¦Ì
		x=road2[i][0];
		y=road2[i][1];
//		node[x]->child[node[x]->yezishu]=(BiTNode*)malloc(sizeof(BiTNode));
		node[x]->child[node[x]->childnum]=node[y];
		node[x]->childnum++;
//		node[y]->child[node[y]->yezishu]=(BiTNode*)malloc(sizeof(BiTNode));
		node[y]->child[node[y]->childnum]=node[x];
		node[y]->childnum++;
//		printf("%d  y=%d\n",node[x]->child[node[x]->yezishu-1]->data,y);
//		printf("%d  x=%d\n",node[y]->child[node[y]->yezishu-1]->data,x);
	}

	GROUP=0;
	for (i=0; i<n; i++) {
		if (node[index[i]]->group == -1) {//¨°?index[i]?a?e¦Ì?¡ä¡ä?¡§¨º¡Â¡ê?¡ã??¨´¨®D¨¢?¨ª¡§¦Ì?¦Ì?¡ä¨°¨¦?¡À¨º??
			_group(node[index[i]],0,GROUP);
			GROUP++;
		}
	}

	for (i=0; i<GROUP; i++) {
		cluster[i].max = -1;
		cluster[i].time = 0;
		cluster[i].member = 0;
	}
	for (i=0; i<n; i++) {
		cluster[node[index[i]]->group].time += node[index[i]]->time;
		cluster[node[index[i]]->group].member++;
		if (node[index[i]]->time > cluster[node[index[i]]->group].max) {
			cluster[node[index[i]]->group].max = node[index[i]]->time;
			strcpy(cluster[node[index[i]]->group].head,node[index[i]]->name);
		}
	}

	total=0;
	for (i=0; i<GROUP; i++) {
		if ((cluster[i].time/2 > k) && (cluster[i].member > 2)) {
			out[total] = cluster[i];
			total++;
		}
	}
	namesort2(out,total);
	printf("%d",total);
	for (i=0; i<total; i++) {
		printf("\n%s %d",out[i].head,out[i].member);
	}

	//free
	return 0;
}

void _group(Node *root,int L,int GROUP) {
//	int max=-1,h=1;
	int i;
//	printf("\nBEGIN\n");
	if(root==NULL) {
		root->level=L;//?a???¡äDD?a¨º2?¡ä2??¨¢3?¡ä¨ª¡ê?¡ê?¡ê?¡ê? //o???2??¨¢?¡äDD¦Ì??a¨¤?¡ê?¨°¨°?achild??2??¨¢¨º?NULL
//		max=0;//¨®?return¦Ì??¡ão¨®???1?¨¢?¨¬D?¡Á??e ¡ê?¨®?max=0¨º?2?¨º?root=NULL?¨ª?T?T?-?¡¤¨¢?
	} else {
		root->level=L+1;
		root->group = GROUP;
		for (i=0; i<root->nodenum; i++) {
//			printf("root=%d  level=%d\n",root->data,root->level);
			if (root->child[i]->level == max) {//> root->level
//				printf("child=%d\n\n",root->child[i]->data);
				_group(root->child[i],root->level,GROUP);
			}
		}
	}
//	printf("\nEND\n");
}

void namesort2(Cluster *bill,int n) {
	int i,j;
	Cluster na;

	for (i=0; i<n; i++) {
		for (j=i+1; j<n; j++) {
			if (strcmp(bill[i].head,bill[j].head) > 0) {
				na=bill[i];
				bill[i]=bill[j];
				bill[j]=na;
			}
		}
	}
}
