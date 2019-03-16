#include <stdio.h>
#include <stdlib.h>

const int MAX = 600*10000;

typedef struct _node {
	int value;//1??¨ªD¨°o?
	int time;
	int needtime;
	struct _node *next;
} Node;

typedef struct _list {
	int wait;
	Node* head;
//	Node* tail;
} List;

typedef struct _customer {
	int t;
	int arrive;
	int END;
} CUS;

CUS customer[10010];
List list[110];
int n,m=1,k;

void add(int i,int number,int t);
void delet(int number,int i);
void _free(int i);
int _find();
void sort();

void add(int i,int number,int t) {
	Node *p = (Node*)malloc(sizeof(Node));

	list[i].wait++;
	p->value = number;
	p->time = t;
	p->needtime = t;
//	p->endtime = MAX;
	p->next = NULL;
	Node *last = list[i].head;
	if (last) {
		while (last->next) {
			last = last->next;
		}
		last->next = p;
	} else {
		list[i].head = p;
	}
}

void delet(int i,int end) {
	Node *p;

	list[i].wait--;
	p = list[i].head;
	customer[p->value].END = end;
	list[i].head = p->next;
	free(p);
}

void _free(int i) {
	Node *p,*q;
	for (p=list[i].head; p; p=q) {
		q=p->next;
		free(p);
	}
}

int main(void) {
	int i,j,maxt=0,allcus=0,nextArrive=0;
	long long int allwait=0;
	char *str;
	int Time;
	int MM=9;

	scanf("%d%d",&k,&n);
	int line1,line2,CUSTOMER;

	for (i=0; i<n; i++) {
		list[i].head = NULL;
		list[i].wait = 0;
	}

	str=(char*)malloc(MM*sizeof(char));
	for (i=0; i<k; i++) {
		scanf("%s",str);
//		printf("%s",str);
		//¡ã??¨¢¦Ì?¦Ì?¨º¡À??-8¦Ì?¡Áa3¨¦¨ºy¡Á?¡¤?¨¨?arrive
		customer[i].arrive = (str[0]-'0')*3600*10+(str[1]-'0')*3600+(str[3]-'0')*60*10+(str[4]-'0')*60+(str[6]-'0')*10+(str[7]-'0') - 3600*8;
		scanf("%d",&Time);
//		printf("%d\n",customer[i].t);
		customer[i].t =(int)(Time * 60);
		if (customer[i].t > maxt) {
			maxt = customer[i].t;
		}
		customer[i].END = MAX;
	}
	//¡ã¡ä¦Ì?¡ä?¨º¡À????DD??D¨°
	sort();

	line2 = 0;
	for (i=0; i<k; i++) {//8¦Ì??¡ã¦Ì?¦Ì?¨¨?¨ºy
		if (customer[i].arrive < 0) {
			line2++;
		}
	}
	nextArrive = line2;
	line1 = 0;
	CUSTOMER = 0;
	for (i=0; i<(541+maxt)*60; i++) {
		//?¨¬2¨¦?a¨°???¨º?¡¤?¨®D¨¨?¦Ì?¨¢?¡ê?¦Ì?¨¢?line2++
//		for (j=0; j<k; j++) {
		if (customer[nextArrive].arrive == i) {
//				CUSTOMER = j;
			line2++;
			nextArrive++;
		}
//		}
		for (j=0; j<n; j++) {
			if ( (list[j].head) && (( (list[j].head)->needtime) == 0) ) {
				delet(j,i);
				line1--;
			}
		}

		while ((line1 < n*m) && (line2 > 0)) {
			j = -1;
			j = _find();
//			printf("¨º¡À??=%d  ?¨®¨¨?¦Ì¨²??o?¡ä¡ã?¨²=%d\n",i,j);
			if (j != -1) {
				add(j,CUSTOMER,customer[CUSTOMER].t);
				CUSTOMER++;
				line1++;
				line2--;
			} else {
			}

		}

		for (j=0; j<n; j++) {
			if (list[j].head) {
				(list[j].head)->needtime--;
			}
		}
	}

	for (i=0; i<k; i++) {
		if (customer[i].arrive <= 540*60) {
//		if ((customer[i].END - customer[i].t) <= 540*60) {
			allwait += customer[i].END - customer[i].t - customer[i].arrive;
			allcus++;
		}
	}
	printf("%.1f",(allwait/60.0)/allcus);

	for (i=0; i<n; i++) {
		_free(i);
	}

	return 0;
}

void sort() {
	int i,j;
	CUS a;

	for (i=0; i<k; i++) {
		for (j=i; j<k; j++) {
			if (customer[i].arrive > customer[j].arrive) {
				a = customer[i];
				customer[i] = customer[j];
				customer[j] = a;
			}
		}
	}
}

int _find() {
	int j=-1,i,w=MAX;

	for (i=0; i<n; i++) {
		if (((list[i].wait) < w) && ((list[i].wait) < m)) {
			w = list[i].wait;
			j = i;
		}
	}

	return j;
}
