#include <stdio.h>
#include <stdbool.h>

char str1[20],str2[20];
int len;
int s1[20],s2[20];

bool radix(int,int);

int main(void) {
	int i,j,n,b;
	bool yes;

	scanf("%d%d",&n,&b);
	yes=radix(n,b);

	if (yes) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
//	for (i=0;i<len;i++){
//		printf("%c ",str2[i]);
//	}
//	printf("%c",str2[len]);
	for (i=0; i<len; i++) {
		printf("%d ",s2[i]);
	}
	printf("%d",s2[len]);

	return 0;
}

//????¡Áa??
bool radix(int number,int r1) {
	int i,j,rest,a[100];
	bool yes=true;

	i=0;
	if (number == 0) {
		i=1;
		a[0] = 0;
		s1[0]=0;
//		str1[0] = '0';
		len = 0;
	} else {
		rest = number;
		while (rest > 0) {
			a[i] = rest % r1;
			s1[i]=a[i];
//			str1[i] = a[i] + '0';
			rest = rest / r1;
//		printf("%d ",a[i]);
			i++;
		}
		len = i-1;
	}
	for (j=0; j<i; j++) {
//		str2[j] = str1[len-j];
//		if (str2[j] != str1[j]){
//			yes=false;
//		}
		s2[j]=s1[len-j];
		if (s2[j] != s1[j]) {
			yes=false;
		}
	}

	return yes;
}
