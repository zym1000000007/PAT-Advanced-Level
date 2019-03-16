#include <stdio.h>
#include <string.h>

int main(void) {
	char str[81];
	int n1,n2,N,i,j;

	scanf("%s",str);

	N=strlen(str);
	if ((N+2)%3 == 0) {
		n2 = N/3 + 1;
	} else {
		n2 = N/3 + 2;
	}

	n1 = (N + 2 - n2) / 2;
	for (i=0; i<n1-1; i++) {
		printf("%c",str[i]);
		for (j=0; j<n2-2; j++) {
			printf(" ");
		}
		printf("%c\n",str[N-1-i]);
	}
	for (i=n1-1; i<=n1+n2-2; i++) {
		printf("%c",str[i]);
	}

	return 0;
}
