#include <stdio.h>
#include <string.h>

//enum NUM {zero,one,two,three,four,five,six,seven,eight,nine
//         };

int main(void) {
	char str[200];
	int num[200],a[200]= {0};
	int len,i,sum=0,j;
//	char n0[]="zero",n1[]="one",n2[]="two",n3[]="three",n4[]="four",n5[]="five",n6[]="six",n7[]="seven",n8[]="eight",n9[]="nine";
//	char *number[10]={n0,n1,n2,n3,n4,n5,n6,n7,n8,n9};
	const char *number[10];

	scanf("%s",str);
//	printf("%s\n",str);
	len = strlen(str);
//	printf("len=%d\n",len);
	for (i=0; i<len; i++) {
//		printf("%c\n",str[i]);
		num[i]=str[i]-'0';
		sum=sum+num[i];
//		printf("%d\n",num[i]);
	}
	i=0;
	while (sum>0) {
		a[i] = sum % 10;
		sum = sum / 10;
		i++;
	}
//	printf("i=%d  number[a[i-1]]=%d\n",i,number[a[i-1]]);

	number[0] = "zero";
	number[1] = "one";
	number[2] = "two";
	number[3] = "three";
	number[4] = "four";
	number[5] = "five";
	number[6] = "six";
	number[7] = "seven";
	number[8] = "eight";
	number[9] = "nine";

	if (i==0)i++;
//	printf("i=%d\n",i);
	printf("%s",number[a[i-1]]);
	for (j=i-2; j>=0; j--) {
		printf(" %s",number[a[j]]);
	}


	return 0;
}
