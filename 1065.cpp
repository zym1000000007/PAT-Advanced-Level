#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sign,N;

int* turn(char* A) {
	int n = strlen(A);
	int i,yes,j,head,begin;
	int *B = (int*)malloc(n*sizeof(int));
	if (A[0] == '-') {
		begin = 1;
		sign = 1;
	} else if (A[0] == '+') {
		begin = 1;
		sign = 0;
	} else {
		begin = 0;
		sign = 0;
	}
	head = 0;
	j = 0;
	for (i=begin; i<n; i++) {
		if ((A[i] == '0') && (head == 0)) {
		} else {
			B[j] = A[i] - '0';
			head = 1;
			j++;
		}
	}
	if (j == 0) {
		N = 1;
		B[0] = 0;
		sign = 1;
	} else {
		N = j;
	}

	return B;
}

int max(int x,int y) {
	if (x > y) {
		return x;
	} else {
		return y;
	}
}

int* add1(int* a,int na,int* b,int nb) {
	int nc = max(na,nb)+1;
	int jinwei,i;
	int *c;
	int *c1 = (int*)malloc(nc*sizeof(int));
	int *a1 = (int*)malloc(nc*sizeof(int));
	int *b1 = (int*)malloc(nc*sizeof(int));
	for (i=0; i<na; i++) {
		a1[nc-na+i] = a[i];
	}
	for (i=0; i<nc-na; i++) {
		a1[i] = 0;
	}
	for (i=0; i<nb; i++) {
		b1[nc-nb+i] = b[i];
	}
	for (i=0; i<nc-nb; i++) {
		b1[i] = 0;
	}
	jinwei = 0;
	for (i=nc-1; i>=0; i--) {
		c1[i] = a1[i] + b1[i] + jinwei;
		jinwei = 0;
		if (c1[i] >= 10) {
			c1[i] -= 10;
			jinwei = 1;
		}
	}
	i = 0;
	while (c1[i] == 0) {
		i++;
	}
	if (i < nc) {
		c = &c1[i];
		N = nc - i;
	} else {
		c = &c1[nc-1];
		N = 1;
	}
//	if (c1[0] == 0) {
//		c = &c1[1];
//		N = nc - 1;
//	} else {
//		c = c;
//		N = nc;
//	}
	return c;
}

int* add2(int* a,int na,int* b,int nb) {
	int nc = max(na,nb)+1;
	int jinwei,i,s;
	int *c;
	int *c1 = (int*)malloc(nc*sizeof(int));
	int *a1 = (int*)malloc(nc*sizeof(int));
	int *b1 = (int*)malloc(nc*sizeof(int));
	int *a2;
	int *b2;
	for (i=0; i<na; i++) {
		a1[nc-na+i] = a[i];
	}
	for (i=0; i<nc-na; i++) {
		a1[i] = 0;
	}
	for (i=0; i<nb; i++) {
		b1[nc-nb+i] = b[i];
	}
	for (i=0; i<nc-nb; i++) {
		b1[i] = 0;
	}
	s = 0;
	for (i=0; i<nc; i++) {
		if (a1[i] > b1[i]) {
			s = 1;
			break;
		} else if (a1[i] < b1[i]) {
			s = -1;
			break;
		}
	}
	if (s == 1) {
		a2 = a1;
		b2 = b1;
		sign = 0;
	} else if (s != 1) {
		a2 = b1;
		b2 = a1;
		sign = 1;
	}
	jinwei = 0;
	for (i=nc-1; i>=0; i--) {
		c1[i] = a2[i] - b2[i] + jinwei;
		jinwei = 0;
		if (c1[i] < 0) {
			c1[i] += 10;
			jinwei = -1;
		}
	}
	i = 0;
	while (c1[i] == 0) {
		i++;
	}
	if (i < nc) {
		c = &c1[i];
		N = nc - i;
	} else {
		c = &c1[nc-1];
		N = 1;
	}

	return c;
}

int* sum(int* a,int signA,int na,int* b,int signB,int nb) {
	int *c,signc;
	if ((!signA) && (!signB)) {
		c = add1(a,na,b,nb);
		signc = 0;
	} else if ((signA) && (signB)) {
		c = add1(a,na,b,nb);
		signc = 1;
	} else if ((!signA) && (signB)) {
		c = add2(a,na,b,nb);
		signc = sign;
	} else if ((signA) && (!signB)) {
		c = add2(b,nb,a,na);
		signc = sign;
	}
	sign = signc;
	return c;
}

int main(void) {
	int i,j,n,SC;
	char A[100],B[100],C[100];

	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%s%s%s",A,B,C);
		int *a = turn(A);
		int signA = sign;
		int na = N;
		int *b = turn(B);
		int signB = sign;
		int nb = N;
		int *c = turn(C);
		int signC = sign;
		int nc = N;
		int *d = sum(a,signA,na,b,signB,nb);
		int signD = sign;
		int nd = N;
		SC = 1 - signC;
		if ((signC == 1) && (c[0] == 0)) {
			SC = 1;
		}
		int *e = sum(d,signD,nd,c,SC,nc);
		int signE = sign;
		int ne = N;
//		printf("signa=%d na=%d\n",signA,na);
//		for (j=0; j<na; j++) {
//			printf("%d",a[j]);
//		}
//		printf("\n");
//		printf("signb=%d nb=%d\n",signB,nb);
//		for (j=0; j<nb; j++) {
//			printf("%d",b[j]);
//		}
//		printf("\n");
//		printf("signc=%d nc=%d\n",signC,nc);
//		for (j=0; j<na; j++) {
//			printf("%d",c[j]);
//		}
//		printf("\n");
//		printf("signd=%d nd=%d\n",signD,nd);
//		for (j=0; j<nd; j++) {
//			printf("%d",d[j]);
//		}
//		printf("\n");
//		printf("signe=%d ne=%d\n",signE,ne);
//		for (j=0; j<ne; j++) {
//			printf("%d",e[j]);
//		}
//		printf("\n");
		if (signE == 0) {
			printf("Case #%d: true\n",i+1);
		} else {
			printf("Case #%d: false\n",i+1);
		}
	}

	return 0;
}
