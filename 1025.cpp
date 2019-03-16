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

//分治法把数组分成两份
int patition(Node *a, int left,int right) {
	int yes;
	int j = left;    //用来遍历数组
	int i = j - 1;    //用来指向小于基准元素的位置
	Node key = a[right];    //基准元素
	//从左到右遍历数组，把小于等于基准元素的放到左边，大于基准元素的放到右边
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
		if (cmp(&a[j],&key) < 0)//为什么比上次提交快这么多？又被自动优化了？换纯手写试试//好像是因为上次有等于号的缘故，多了很多次交换 
			swap(&a[j], &a[++i]);
	}
	//把基准元素放到中间
	swap(&a[right], &a[++i]);
	//返回数组中间位置
	return i;
}
//快速排序
void quickSort(Node *a,int left,int right) {
	if (left>=right)//要不要改成<？？？
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
