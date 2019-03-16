#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long long int s[2000],len1,len2,len3;
long long int st1[2000],st2[2000],st3[2000];

void add();
void radix(long long int,long long int);
bool palindromic();

int main(void) {
	long long int i,j,k,ci,num;
	long long int n;
	bool yes;

	scanf("%lld%d",&n,&k);

	len3=0;
	//¡ã?n¡À?3¨¦¨ºy¡Á¨¦
	radix(n,10);
	yes = palindromic();
	if (yes) {
		ci=0;
	} else {
		ci = k;
		for (i=0; i<k; i++) {
			for (j=0; j<len3; j++) {
				st1[j]=st3[j];
				st2[j]=s[j];
			}
			add();
			yes=palindromic();
			if (yes) {
				ci=i+1;
				i=k;
			}
			n=num;
		}
	}

	for (i=0; i<len3; i++) {
		printf("%d",s[i]);
	}
	printf("\n%d",ci);

	return 0;
}

void add() {
	int i,j,jinwei=0,sum;

//	if (len1>len2){
//		len3 = len1;
//	} else {
//		len3 = len2;
//	}
	for (i=0; i<len3; i++) {
		sum=st1[i]+st2[i]+jinwei;
		jinwei=0;
		if (sum >= 10) {
			st3[i]=sum-10;
			jinwei=1;
		} else {
			st3[i]=sum;
		}
//		printf("sum=%d   st3=%d\n",sum,st3[i]);
	}
	if (jinwei == 1) {
		st3[len3]=1;
		len3++;
	}
//	for (i=0; i<len3; i++) {
//		printf("%d  %d  %d\n",st1[i],st2[i],st3[i]);
//	}
}

void radix(long long int number,long long int r1) {
	long long int i,rest,a[2000];

	i=0;
	if (number == 0) {
		i=1;
		a[0] = 0;
//		st1[0]=0;
		st3[0]=0;
	} else {
		rest = number;
		while (rest > 0) {
			a[i] = rest % r1;
//			st1[i]=a[i];
			st3[i]=a[i];
			rest = rest / r1;
			i++;
		}
	}
	len3=i;
//	for (i=0; i<len3; i++) {
//		printf("%d",st3[i]);
//	}
//	printf("\nlen3=%d\n",len3);
}

bool palindromic() {
	long long int i,j,rest,a[2000];
	bool yes=true;

	for (j=0; j<len3; j++) {
		s[j]=st3[len3-j-1];
		if (s[j] != st3[j]) {
			yes=false;
//			j=len3;
		}
	}
//	for (i=0; i<len3; i++) {
//		printf("%d",s[i]);
//	}
//	printf("\nlen3\n");

	return yes;
}
