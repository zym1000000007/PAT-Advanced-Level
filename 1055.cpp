#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int age,worth;
	char name[10];
} Node;

int cmp(const void*a,const void*b) {
	int judge;
	Node *p=(Node*)a;
	Node *q=(Node*)b;
	if (p->worth != q->worth) {
		judge = q->worth - p->worth;
	} else if (p->age != q->age) {
		judge = p->age - q->age;
	} else {
		judge = strcmp(p->name,q->name);
	}
	return judge;
}

int main(void) {
	int i,j,n,k,m,amin,amax,cnt;

	scanf("%d%d",&n,&k);
	Node node[n];

	for (i=0; i<n; i++) {
		scanf("%s%d%d",node[i].name,&node[i].age,&node[i].worth);
	}

	qsort(node,n,sizeof(node[0]),cmp);

	for (i=0; i<k; i++) {
		scanf("%d%d%d",&m,&amin,&amax);
		cnt = 0;
		if (i > 0) {
			printf("\n");
		}
		printf("Case #%d:",i+1);
		for (j=0; j<n; j++) {
			if ((node[j].age >= amin) && (node[j].age <= amax)) {
				printf("\n%s %d %d",node[j].name,node[j].age,node[j].worth);
				cnt++;
			}
			if (cnt >= m) {
				break;
			}
		}
		if (cnt == 0) {
			printf("\nNone");
		}
	}

	return 0;
}
