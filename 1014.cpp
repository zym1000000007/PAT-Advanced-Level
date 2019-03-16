#include <stdio.h>
#include <stdlib.h>

const int max=123456789;

typedef struct _Node {
	int id,time,begin;
} Node;

typedef struct _Window {
	struct _Node *node;
	struct _Window *next;
} Window;

typedef struct _List {
	int num,rest;
	struct _Window *head,*tail;
} List;

void add(List *list,Node *node) {
	Window *p = (Window*)malloc(sizeof(Window));
	p->node = node;
	p->next = NULL;
	if (list->tail) {
		list->tail->next = p;
		list->tail = p;
	} else {
		list->rest = node->time;
		list->head = p;
		list->tail = p;
	}
	list->num++;
}

void delet(List *list) {
	if (list) {
		Window *p = list->head;
		if (p) {
			list->head = p->next;
			if (list->head) {
				list->rest = list->head->node->time;
			}
			free(p);
			list->num--;
		}
	}
}

void find(Node *node,List **list,int n,int m) {
	int i,min=max,u;
	for (i=0; i<n; i++) {
		if ((list[i]->num < min) && (list[i]->num < m)) {
			min = list[i]->num;
			u = i;
		}
	}
	add(list[u],node);
}

int main(void) {
	int i,j,n,m,k,q,line,turn,Lmax,x,w,T,y,z;

	scanf("%d%d%d%d\n",&n,&m,&k,&q);
	Node node[k];
	List *list[n];
	for (i=0; i<n; i++) {
		list[i] = (List*)malloc(sizeof(List));
		list[i]->head = NULL;
		list[i]->tail = NULL;
		list[i]->num = 0;
	}

	for (i=0; i<k; i++) {
		scanf("%d",&x);
		node[i].time = x;
		node[i].id = i+1;
		node[i].begin = 540;
	}
	line = 0;
	turn = 0;
	Lmax = n*m;
	for (i=0; i<540; i++) {
//        printf("i=%d\n",i);
		for (j=0; j<n; j++) {
			if ((list[j]->head) && (list[j]->rest == 0)) {
				delet(list[j]);
				line--;
			}
		}
		while ((line < Lmax) && (turn < k)) {
			find(&node[turn++],list,n,m);
			line++;
		}
		for (j=0; j<n; j++) {
			if (list[j]->head) {
//                printf("head=%d rest=%d\n",list[j]->head->node->id,list[j]->rest);
				if (list[j]->rest == list[j]->head->node->time) {
					list[j]->head->node->begin = i;
//                    printf("id=%d begin=%d finish=%d\n",list[j]->head->node->id,list[j]->head->node->begin,list[j]->head->node->begin+list[j]->head->node->time);
				}
				if (list[j]->rest > 0) {
					list[j]->rest--;
				}
			}

		}
//        if (turn >= k)
//        {
//            break;
//        }
	}
	for (i=0; i<q; i++) {
		scanf("%d",&x);
		if (node[x-1].begin < 540) {
			T = node[x-1].begin+node[x-1].time + 480;
			x = T/60/10;
			y = T/60%10;
			z = T%60/10;
			w = T%60%10;
			printf("%d%d:%d%d\n",x,y,z,w);
		} else {
			printf("Sorry\n");
		}
//        printf("%d\n",node[x-1].begin+node[x-1].time);
	}

	return 0;
}

