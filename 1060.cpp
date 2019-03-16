#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* firstN(char a[101],int n) {
	int i=0,j=0;
	int head=1;
	char *an=(char*)malloc((n+1)*sizeof(char));

//	printf("a=%s\n",a);
	while ((a[i] != '\0') && (j < n)) {
		if (head == 0) {
			if (a[i] != '.') {
				an[j] = a[i];
				j++;
			}
		} else {
			if ((a[i] != '0') && (a[i] != '.')) {
				an[j] = a[i];
				j++;
				head = 0;
			}

		}
		i++;
	}
	if (j < n) {
		for (i=j; i<n; i++) {
			an[i] = '0';
		}
	}
	an[n] = '\0';
//	printf("an=%s\n",an);

	return an;
}

int length(char a[101]) {
	int i=0,j,k=-1;
	int head=0,dot=0;
	int back;

	while (a[i] != '\0') {
		if ((a[i] != '0') && (a[i] != '.')) {
			head = 1;
			j = i;
			break;
		}
		i++;
	}
	if (head == 0) {
		j = i;
	}
	i=0;
	while (a[i] != '\0') {
		if ((a[i] == '.')) {
			k = i;
			dot = 1;
			break;
		}
		i++;
	}
	if (dot == 0) {
		k = i;
	}
//	printf("j=%d k=%d",j,k);
	back = k - j;
	if (back < 0) {
		back += 1;
	}
	if (head == 0)  {
		back = 0;
	}
	return back;
}

int main(void) {
	int i,j,n,na,nb;
	char a[101],b[101],*an,*bn;

	scanf("%d",&n);
	scanf("%s",a);
	scanf("%s",b);

	an = firstN(a,n);
	bn = firstN(b,n);
	na = length(a);
	nb = length(b);

	if ((strcmp(an,bn) == 0) && (na == nb)) {
		printf("YES 0.%s*10^%d",an,na);
	} else {
		printf("NO 0.%s*10^%d 0.%s*10^%d",an,na,bn,nb);
	}
//	printf("%s\n%s\n",an,bn);
//	printf("%d %d",na,nb);

	return 0;
}
