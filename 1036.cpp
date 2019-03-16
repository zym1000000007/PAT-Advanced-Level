#include <stdio.h>
#include <string.h>

typedef struct _Node {
	int grade;
	char ID[12],name[12];
} Node;

int main(void) {
	int i,j,n,grade,x=0,y=0;
	char gender,name[12],ID[12];

	scanf("%d",&n);
	Node boy[n],girl[n],boymax,girlmax;

	boymax.grade = 101;
	girlmax.grade = -1;
	for (i=0; i<n; i++) {
		scanf("%s %c %s%d",name,&gender,ID,&grade);
		if (gender == 'M') {
			boy[x].grade = grade;
			strcpy(boy[x].name,name);
			strcpy(boy[x].ID,ID);
			if (grade < boymax.grade) {
				boymax = boy[x];
//				printf("x=%d\n",x);
//				printf("%s %s %d\n",boy[x].name,boy[x].ID,boy[x].grade);
//				printf("%s %d\n",boymax.name,boymax.grade);
			}
			x++;
		} else if (gender == 'F') {
			girl[y].grade = grade;
			strcpy(girl[y].name,name);
			strcpy(girl[y].ID,ID);
			if (grade > girlmax.grade) {
				girlmax = girl[y];
			}
			y++;
		}
	}
//	for (i=0;i<x;i++) {
//		printf("%s %s %d\n",boy[i].name,boy[i].ID,boy[i].grade);
//	}
	if (y == 0) {
		printf("Absent\n");
	} else {
		printf("%s %s\n",girlmax.name,girlmax.ID);
	}
	if (x == 0) {
		printf("Absent\n");
	} else {
		printf("%s %s\n",boymax.name,boymax.ID);
	}
	if ((x != 0) && (y != 0)) {
		printf("%d",girlmax.grade-boymax.grade);
	} else {
		printf("NA");
	}

	return 0;
}
