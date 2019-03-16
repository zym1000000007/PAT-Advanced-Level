#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **str;

int cmp(const void*a,const void*b) {
	int judge;
	char *p = *(char**)a;
	char *q = *(char**)b;
	char p1[20],q1[20],p2[20],q2[20];
//	printf("p=%s q=%s\n",p,q);
	strcpy(p1,p);
	strcpy(q1,q);
	strcpy(p2,p);
	strcpy(q2,q);
	char *x = strcat(p1,q1);
	char *y = strcat(q2,p2);
	judge = strcmp(x,y);
//	printf("%s %s\n",p,q);
	return judge;
}

int main(void) {
	int i,j,n,lead;

	scanf("%d",&n);

	str = (char**)malloc(n*sizeof(char*));
	for (i=0; i<n; i++) {
		str[i] = (char*)malloc(10*sizeof(char));
		scanf("%s",str[i]);
	}

	qsort(str,n,sizeof(str[0]),cmp);

	lead = 1;
	for (i=0; i<n; i++) {
		for (j=0; j<strlen(str[i]); j++) {
			if ((lead == 1) && (str[i][j] == '0')) {
			} else {
				printf("%c",str[i][j]);
				lead = 0;
			}
		}
	}
	if (lead) {
		printf("0");
	}

	return 0;
}
