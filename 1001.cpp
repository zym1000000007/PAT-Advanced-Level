#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
	int a,b,c,len,i,j;
	char str[30],str2[10][4];

	scanf("%d %d",&a,&b);
	c=a+b;
	sprintf(str,"%d",abs(c));
	len = strlen(str);
	j=0;
	for (i=len-1; i>=2; i=i-3) {
		str2[j][2]=str[i];
		str2[j][1]=str[i-1];
		str2[j][0]=str[i-2];
		str2[j][3]='\0';
		j++;
	}
	if (i==1) {
		str2[j][1]=str[1];
		str2[j][0]=str[0];
		str2[j][2]='\0';
	} else if (i==0) {
		str2[j][0]=str[0];
		str2[j][1]='\0';
	} else {
		j=j-1;
	}
	if (c<0) {
		printf("-");
	}
	for (i=j; i>0; i--) {
		printf("%s,",str2[i]);
	}
	printf("%s",str2[0]);

	return 0;
}
