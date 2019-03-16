#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int grade,tseq,lseq,test;
	char name[20];
} Node;

int cmp(const void*a,const void*b) {
	Node *p = (Node*)a;
	Node *q = (Node*)b;
	if (p->grade != q->grade) {
		return q->grade - p->grade;
	} else {
		return strcmp(p->name,q->name);
	}
}

void swap(Node *x, Node *y) {
	Node tmp = *x;
	*x = *y;
	*y = tmp;
}

//���η�������ֳ�����
int patition(Node *a, int left,int right) {
	int yes;
	int j = left;    //������������
	int i = j - 1;    //����ָ��С�ڻ�׼Ԫ�ص�λ��
	Node key = a[right];    //��׼Ԫ��
	//�����ұ������飬��С�ڵ��ڻ�׼Ԫ�صķŵ���ߣ����ڻ�׼Ԫ�صķŵ��ұ�
	for (; j < right; ++j) {
//		Node p = a[j];
//		Node q = key;
//		if (p.grade != q.grade) {
//			yes = q.grade - p.grade;
//		} 
//		else {
//			yes = strcmp(p.name,q.name);
//		}
//		if (yes < 0)
//		if (a[j].grade > key.grade)
		if (cmp(&a[j],&key) < 0)//Ϊʲô���ϴ��ύ����ô�ࣿ�ֱ��Զ��Ż��ˣ�������д����//��������Ϊ�ϴ��е��ںŵ�Ե�ʣ����˺ܶ�ν��� 
			swap(&a[j], &a[++i]);
	}
	//�ѻ�׼Ԫ�طŵ��м�
	swap(&a[right], &a[++i]);
	//���������м�λ��
	return i;
}
//��������
void quickSort(Node *a,int left,int right) {
	if (left>=right)//Ҫ��Ҫ�ĳ�<������
		return;
	int mid = patition(a,left,right);
	quickSort(a, left, mid - 1);
	quickSort(a, mid + 1, right);
}

int main(void) {
	int i,j,N,N0,x,lastgrade,lastseq,k;
	char name[20];

	scanf("%d",&N);
	Node node[N*300];
	int n[N],num[N],lastg[N],lasts[N];

	int cnt = 0;
	for (i=0; i<N; i++) {
		scanf("%d",&n[i]);
		for (j=0; j<n[i]; j++) {
			scanf("%s%d",name,&x);
			node[cnt].grade = x;
			node[cnt].test = i;
			strcpy(node[cnt].name,name);
			cnt++;
		}
	}
	N0 = cnt;
	quickSort(node,0,N0-1);
//	qsort(node,N0,sizeof(node[0]),cmp);

	lastgrade = -1;
	lastseq = -1;
	for (i=0; i<N; i++) {
		num[i] = 1;
		lastg[i] = -1;
		lasts[i] = -1;
	}
	for (i=0; i<N0; i++) {
		if (node[i].grade == lastgrade) {
			node[i].tseq = lastseq;
		} else {
			node[i].tseq = i + 1;
			lastgrade = node[i].grade;
			lastseq = i + 1;
		}
		k = node[i].test;
		if (node[i].grade == lastg[k]) {
			node[i].lseq = lasts[k];
		} else {
			node[i].lseq = num[k];
			lasts[k] = node[i].lseq;
			lastg[k] = node[i].grade;
		}
		num[k]++;
	}

	printf("%d\n",N0);
	for (i=0; i<N0; i++) {
		printf("%s %d %d %d\n",node[i].name,node[i].tseq,node[i].test+1,node[i].lseq);
	}

	return 0;
}
