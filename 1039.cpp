#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size=10*26*26*26+10;

typedef struct _Course {
//	char **name;
	int num;
	int *stu;
} Course;

typedef struct _Student {
	char name[5];
	int *course,cournum,k,que;
} Student;

Student student[10*26*26*26+10];

void sort(int *x,int n) {
	int i,j,a;

	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			if (x[i] > x[j]) {
				a=x[i];
				x[i]=x[j];
				x[j]=a;
			}
		}
	}
}

int main(void) {
	int i,j,n,m,k,d,e,in;
	char name[5];

	scanf("%d%d",&n,&m);
	Course course[m];
	int index[n];

	for (i=0; i<size; i++) {
		student[i].cournum=0;
		student[i].que=0;
//		student[i].k = 0;
	}
//	for (i=0;i<m;i++) {
//		course[i].stu = (int*)malloc(210*sizeof(int));
//	}
	for (i=0; i<m; i++) {
		scanf("%d%d",&d,&e);
		d--;
		course[d].num = e;
		course[d].stu = (int*)malloc(e*sizeof(int));
		for (j=0; j<e; j++) {
			scanf("%s",name);
//			in = (name[3] - '0')*26*26*26 + (name[2] - 'A')*26*26+ (name[1] - 'A')*26 + (name[0] - 'A');
			in = (name[0] - 'A')*26*26*10 + (name[1] - 'A')*26*10+ (name[2] - 'A')*10 + (name[3] - '0');
			course[d].stu[j] = in;
			student[in].cournum++;
		}
	}

	for (i=0; i<n; i++) {
		scanf("%s",name);
		in = (name[0] - 'A')*26*26*10 + (name[1] - 'A')*26*10+ (name[2] - 'A')*10 + (name[3] - '0');
//		in = (name[3] - '0')*26*26*26 + (name[2] - 'A')*26*26+ (name[1] - 'A')*26 + (name[0] - 'A');
		index[i] = in;
		strcpy(student[in].name,name);
		student[in].course = (int*)malloc(student[in].cournum*sizeof(int));
		student[in].k = 0;
		student[in].que = 1;
	}

	for (i=0; i<m; i++) {
		for (j=0; j<course[i].num; j++) {
			in = course[i].stu[j];
			if (student[in].que == 1) {
				student[in].course[student[in].k] = i;
				student[in].k++;
			}
		}
	}

	for (k=0; k<n; k++) {
		i = index[k];
		sort(student[i].course,student[i].cournum);
		if (k > 0) {
			printf("\n");
		}
		printf("%s %d",student[i].name,student[i].cournum);
		for (j=0; j<student[i].cournum; j++) {
			printf(" %d",student[i].course[j]+1);
		}
//		printf("END");
	}

	for (i=0; i<n; i++) {
		free(student[index[i]].course);
	}
	for (i=0; i<m; i++) {
		free(course[i].stu);
	}

	return 0;
}
