#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int len1,len2,len3;
int st1[2000],st2[2000],st3[2000];

void add();

int main(void) {
	char str[21];
	int L,i,num1[10]= {0},num2[10]= {0};
	bool yes=true;

	scanf("%s",str);

	L=strlen(str);
	for (i=0; i<L; i++) {
		st1[i] = str[L-1-i] - '0';
		st2[i] = st1[i];
		num1[st1[i]]++;
	}
	len3=L;
//	for (i=len3-1;i>=0;i--){
//		printf("%d",st1[i]);
//	}
//	printf("\n");
	add();
	for (i=len3-1; i>=0; i--) {
		num2[st3[i]]++;
	}
	for (i=0; i<10; i++) {
		if (num1[i] != num2[i]) {
			yes=false;
		}
	}
	if (yes) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	for (i=len3-1; i>=0; i--) {
		printf("%d",st3[i]);
	}
	//????????¨ºy¡Á?3???¡ä?¨ºy
	return 0;
}

void add() {
	int i,j,jinwei=0,sum;

//	if (len1>len2){
//		len3 = len1;
//	} else {
//		len3 = len2;
//	}
	for (i=0; i<len3; i++) { //st1,st2,st3¨º?¦Ì1D¨°
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
