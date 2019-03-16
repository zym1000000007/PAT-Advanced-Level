#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Str {
	int yes,asc;
} Str;

int main(void) {
	int i,j,n,k,len2,len1;
	char s1[12345],s2[12345];
	Str str1[12345],str2[12345];
	int del[150];
	Str *p,q;

	scanf("%[^\n]",s1);
	scanf("\n");
	scanf("%[^\n]",s2);
	for (i=0; i<150; i++) {
		del[i] = 0;
	}

	len1 = strlen(s1);
	len2 = strlen(s2);
	for (i=0; i<len1; i++) {
		str1[i].asc = s1[i];
		str1[i].yes = 1;
	}
	for (i=0; i<len2; i++) {
		del[s2[i]] = 1;
//		printf("%d\n",str2[i].asc);
	}

	for (j=0; j<len1; j++) {
		if (del[str1[j].asc] == 1) {
			str1[j].yes = 0;
		}
	}
//		printf("%d ",del[i]);

	for (i=0; i<len1; i++) {
		if (str1[i].yes)
			printf("%c",s1[i]);
	}

	return 0;
}
