#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct _student {
	int grade,ID;
	char name[9];
} Student;

void swap(Student **x, Student **y) {
	Student *tmp = *x;
	*x = *y;
	*y = tmp;
}

int patition1(Student **a, int left,int right) {
	int j = left;
	int i = j - 1;
	Student *tmp;
	srand((unsigned int)time(NULL));
	int index = left + rand() % (right - left + 1);
	swap(&a[index],&a[right]);
	Student *key = a[right];

	for (; j < right; ++j) {
		if (a[j]->ID - key->ID < 0) {
			swap(&a[j],&a[++i]);
		}
	}
	swap(&a[right],&a[++i]);
	return i;
}

void InsertSort(Student **a, int left,int right) {
	Student *tmp;
	for (int i = left+1; i <= right; i++) {
		int j = i - 1;
		if (a[i]->ID < a[j]->ID) {
			tmp = a[i];
			a[i] = a[j];
			while ((tmp->ID < a[j-1]->ID) && (j > left)) {
				a[j] = a[j-1];
				j--;
			}
//			printf("i=%d tmp=%d j=%d\n",i,tmp,j);
			a[j] = tmp;
		}
	}
}

void quickSort1(Student **a,int left,int right) {
	if (left >= right)
		return;
	if (right - left < 128) {
		InsertSort(a,left,right);
	} else {
		int mid;
		mid = patition1(a,left,right);
		quickSort1(a, left, mid - 1);
		quickSort1(a, mid + 1, right);
	}
}

int _type2(Student *a,Student *b) {
	int s;
	if (strcmp(a->name,b->name) != 0) {
		s = strcmp(a->name,b->name);
	} else {
		s = a->ID - b->ID;
	}
	return s;
}

int patition2(Student **a, int left,int right) {
	int j = left;
	int i = j - 1;
	Student *key = a[right];

	for (; j < right; ++j) {
		if (_type2(a[j],key) < 0)
			swap(&a[j], &a[++i]);
	}
	swap(&a[right], &a[++i]);
	return i;
}

void quickSort2(Student **a,int left,int right) {
	if (left>=right)
		return;
	int mid;
	mid = patition2(a,left,right);
	quickSort2(a, left, mid - 1);
	quickSort2(a, mid + 1, right);
}

int _type3(Student *a,Student *b) {
	int s;
	if (a->grade - b->grade != 0) {
		s = a->grade - b->grade;
	} else {
		s = a->ID - b->ID;
	}
	return s;
}

int patition3(Student **a, int left,int right) {
	int j = left;
	int i = j - 1;
	Student *key = a[right];

	for (; j < right; ++j) {
		if (_type3(a[j],key) < 0)
			swap(&a[j], &a[++i]);
	}
	swap(&a[right], &a[++i]);
	return i;
}

void quickSort3(Student **a,int left,int right) {
	if (left>=right)
		return;
	int mid;
	mid = patition3(a,left,right);
	quickSort3(a, left, mid - 1);
	quickSort3(a, mid + 1, right);
}

int main(void) {
	int i,j,n,c,cnt=0,score;
	char str[10];

	scanf("%d%d",&n,&c);
	Student *student[n];
	for (i=0; i<n; i++) {
		student[i] = (Student*)malloc(sizeof(Student));
	}

	for (i=0; i<n; i++) {
		scanf("%d%s%d",&(student[i]->ID),student[i]->name,&(student[i]->grade));
	}

	if (c==1) {
		quickSort1(student,0,n-1);
	} else if (c==2) {
		quickSort2(student,0,n-1);
	} else {
		quickSort3(student,0,n-1);
	}

	i=0;
	printf("%06d %s %d",student[i]->ID,student[i]->name,student[i]->grade);
	for (i=1; i<n; i++) {
		printf("\n%06d %s %d",student[i]->ID,student[i]->name,student[i]->grade);
	}

	return 0;
}
