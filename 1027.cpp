#include <stdio.h>
#include <stdlib.h>

void radix(int,int,char*);

int main(void) {
	int a,b,c;
	char *s1,*s2,*s3;

	scanf("%d%d%d",&a,&b,&c);

	s1=(char*)malloc(3*sizeof(char));
	s2=(char*)malloc(3*sizeof(char));
	s3=(char*)malloc(3*sizeof(char));
	radix(a,13,s1);
	radix(b,13,s2);
	radix(c,13,s3);

	printf("#%s%s%s",s1,s2,s3);

	return 0;
}

void radix(int number,int r1,char *s) {
	int i,rest,a[10];

	i=0;
	a[0]=0;
	a[1]=0;
	rest = number;
	while (rest > 0) {
		a[i] = rest % r1;
		rest = rest / r1;
//		printf("%d ",a[i]);
		i++;
	}
	for (i=0; i<2; i++) {
		if (a[i] < 10) {
			s[1-i] = a[i] + '0';
		} else {
			s[1-i] = a[i] - 10 + 'A';
		}
	}
	s[2]='\0';
}
