#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int turn(char *s,int radix) {
	int len = strlen(s);
	long long int r = 0;
	int i,k;
	for (i=0; i<len; i++) {
		if ((s[i] >= '0') && (s[i] <= '9')) {
			k = s[i] - '0';
		} else if  ((s[i] >= 'a') && (s[i] <= 'z')) {
			k = s[i] - 'a' + 10;
		}
		r = r*radix + k;
	}

	return r;
}

int main(void) {
	int i,j,n,radix,k,max,flag,yes,k0,k1;
	long long int num[2];
	char *s[2],c[2];

	s[0] = (char*)malloc(100*sizeof(char));
	s[1] = (char*)malloc(100*sizeof(char));
	scanf("%s%s%d%d",s[0],s[1],&n,&radix);
	for (j=0; j<2; j++) {
		for (i=0; i<strlen(s[j]); i++) {
			if (s[j][i] != '0') {
				break;
			}
		}
		if (i == strlen(s[j])) {
			i = strlen(s[j]) - 1;
		}
		s[j] = &(s[j][i]);
	}
	n--;
	num[n] = turn(s[n],radix);

	max = 0;
	for (i=0; i<strlen(s[1-n]); i++) {
		c[0] = s[1-n][i];
		c[1] = '\0';
		k = turn(c,2);
//		printf("k=%d\n",k);
		if (k > max) {
			max = k;
		}
	}
	k = max + 1;
//	if (k < 2) {
//		k = 2;
//	}

	if (strlen(s[1-n]) > 2) {
//		flag = 0;
		yes = 1;
		while (turn(s[1-n],k) != num[n]) {
			num[1-n] = turn(s[1-n],k);
			if (num[1-n] > num[n]) {
//				flag++;
//			}
//			if (flag > 0) {
				yes = 0;
				break;
			}
//		printf("k=%d s=%d\n",turn(s[1-n],k));
			k++;
		}
	} else if (strlen(s[1-n]) == 2) {
		c[0] = s[1-n][1];
		c[1] = '\0';
		k1 = turn(c,k);
		if (num[n] > k1) {
			num[1-n] = num[n] - k1;
			c[0] = s[1-n][0];
			c[1] = '\0';
			k0 = turn(c,k);
			if ((num[1-n] % k0 == 0) && (num[1-n] / k0 >= k)) {
				yes = 1;
				k = num[1-n] / k0;
			} else {
				yes = 0;
			}
		} else {
			yes = 0;
		}
	} else {
		if (turn(s[1-n],k) == num[n]) {
			yes = 1;
//			k = turn(s[1-n],k) + 1;
		} else {
			yes = 0;
		}
	}
	if (yes) {
		printf("%d",k);
	} else {
		printf("Impossible");
	}


	return 0;
}
