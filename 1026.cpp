#include <stdio.h>
#include <stdlib.h>

const int max=123456789;

typedef struct _Node {
	int arrive,time,vip,serve,wait;
} Node;

typedef struct _Table {
	int vip,rest,serve;
} Table;

typedef struct _Dot {
	struct _Node *node;
	struct _Dot *next;
} Dot;

typedef struct _List {
	struct _Dot *head,*tail;
} List;

int cmp1(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	return p->arrive - q->arrive;
}

int cmp(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	if (p->serve != q->serve) {
		return p->serve - q->serve;
	} else {
		return p->arrive - q->arrive;
	}
}

void add(List *list,Node *node) {
	Dot *p = (Dot*)malloc(sizeof(Dot));
	p->node = node;
	p->next = NULL;
	if (list->head) {
		list->tail->next = p;
		list->tail = p;
	} else {
		list->head = p;
		list->tail = p;
	}
}

void change(int a) {
	int hour = a /3600;
	int minute = a%3600/60;
	int second = a%60;
	printf("%02d:%02d:%02d",hour,minute,second);
}

int main(void) {
	int i,j,n,hour,minute,second,time,vip,m,k,x,cnt,turn;
	List *list=(List*)malloc(sizeof(List));
	Dot *p,*q,*last;
	list->head = NULL;
	list->tail = NULL;

	scanf("%d",&n);
	Node node[n];

	for (i=0; i<n; i++) {
		scanf("%d:%d:%d%d%d",&hour,&minute,&second,&time,&vip);
		node[i].arrive = hour*60*60+minute*60+second;
		if (time > 120) {
			time = 120;
		}
		node[i].time = time*60;
		node[i].vip = vip;
		node[i].serve = max;
		node[i].wait = -1;
//        printf("%d %d %d %d %d\n",hour,minute,second,time,vip);
	}
	scanf("%d%d",&k,&m);
	Table table[k];
	for (i=0; i<k; i++) {
		table[i].vip = 0;
		table[i].serve = 0;
		table[i].rest = 0;
	}
	for (i=0; i<m; i++) {
		scanf("%d",&x);
		table[x-1].vip = 1;
	}
	qsort(node,n,sizeof(node[0]),cmp1);

	turn = 0;
	for (i=8*60*60; i<21*60*60; i++) {
		while (node[turn].arrive == i) {
			add(list,&node[turn++]);
//            printf("tunr=%d arrive=%d\n",turn,node[turn].arrive);
		}
		j = 0;
		p = list->head;
		last = NULL;
		while ((p) && (j < k)) {
			if ((table[j].rest > 0) || (table[j].vip == 0)) {
				j++;
			} else if (p->node->vip == 0) {
				last = p;
				p = p->next;
			} else {
				table[j].rest = p->node->time;
				table[j].serve++;
				p->node->serve = i;
				p->node->wait = (int)((i - p->node->arrive)/60.0+0.5);
				q = p;
				p = p->next;
				if (last) {
					last->next = p;
				} else {
					list->head = p;
				}
				free(q);
			}
		}
		j = 0;
		p = list->head;
		last = NULL;
		while ((p) && (j < k)) {
			if (table[j].rest > 0) {
				j++;
			} else {
				table[j].rest = p->node->time;
				table[j].serve++;
				p->node->serve = i;
				p->node->wait = (int)((i - p->node->arrive)/60.0+0.5);
				q = p;
				p = p->next;
				if (last) {
					last->next = p;
				} else {
					list->head = p;
				}
				free(q);
			}
		}
		for (j=0; j<k; j++) {
//            printf("j=%d rest=%d\n",j,table[j].rest);
			if (table[j].rest > 0) {
				table[j].rest--;
			}
		}
	}
	qsort(node,n,sizeof(node[0]),cmp);
	for (i=0; i<n; i++) {
		if (node[i].serve == max) {
			break;
		}
		change(node[i].arrive);
		printf(" ");
		change(node[i].serve);
		printf(" %d\n",node[i].wait);
	}
	for (i=0; i<k; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d",table[i].serve);
	}

	return 0;
}

