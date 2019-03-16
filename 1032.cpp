#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int address1,address2,flag;
	char c;
	struct _node *next;
} Node;

Node node[123456];

typedef struct _list {
	Node *head;
} List;

//Node* find(int adr,int n) {
//	int i;
//	Node *p=NULL;
//	for (i=0; i<n; i++) {
////		printf("adr1=%d\n",node[i].address1);
//		if (node[i].address1 == adr) {
//			p=&(node[i]);
//			break;
//		}
//	}
//	return p;
//}

//void add(List *list,Node *p) {
//	Node *node1 = (Node*)malloc(sizeof(Node));
//	*(node1) = *p;
//	if (list->tail) {
//		list->tail->next = node1;
//		node1->last = list->tail;
//		list->tail = node1;
//	} else {
//		list->tail = node1;
//		list->head = node1;
//	}
//}

int main(void) {
	int adr[2],i,j,n,position=-1,x,y;
	char c;
	List list[2];
	Node *p,*q;

	scanf("%d%d%d",&adr[0],&adr[1],&n);

	for (i=0; i<n; i++) {
		scanf("%d %c %d",&x,&c,&y);
		node[x].c = c;
		node[x].address1 = x;
		node[x].address2 = y;
		node[x].flag = 0;
		if (y != -1) {
			node[x].next = &node[y];
//			node[y].last = &node[x];
		} else {
			node[x].next = NULL;
		}
	}
	for (i=0; i<2; i++) {
		if (adr[i] != -1) {
			list[i].head = &node[adr[i]];
		} else {
			list[i].head = NULL;
		}
	}

	for (i=0; i<2; i++) {
		p = list[i].head;
		while (p) {
//			printf("%c\n",p->c);
			p = p->next;
		}
	}

	p=list[0].head;
	q=list[1].head;
	while (p) {
		p->flag = 1;
		p = p->next;
	}
	while (q) {
		if (q->flag == 1) {
			position = q->address1;
			break;
		}
		q = q->next;
	}
//	if ((p) && (q)) {
//		while (p->c != q->c) {
////			printf("%c %05d %c %05d\n",p->c,p->address1,q->c,q->address1);
//			position=p->address1;
//			if ((p->last) && (q->last)) {
//
//				p=p->last;
//				q=q->last;
//			} else {
//				break;
//			}
//		}
//	}

	if (position != -1) {
		printf("%05d",position);
	} else {
		printf("%d",-1);
	}

	return 0;
}
