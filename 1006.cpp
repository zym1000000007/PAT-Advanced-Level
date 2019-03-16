#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *str1[1000],*str2[1000],*str3[1000];
	char *str[4][1000];
	int i,m,j;
	int M=20;
	int min=25*3600,max=0;
	char *ID1,*ID2;

	scanf("%d",&m);
	int a[m][3],b[m][3],A[m],B[m];
	for (i=0; i<m; i++) {
//		str1[i]=(char*)malloc(M*sizeof(char));
//		str2[i]=(char*)malloc(M*sizeof(char));
//		str3[i]=(char*)malloc(M*sizeof(char));
//		scanf("%s%s%s",str1[i],str2[i],str3[i]);
		for (j=1; j<4; j++) {
			str[j][i]=(char*)malloc(M*sizeof(char));
			scanf("%s",str[j][i]);
		}
//		a[i][0]=10*(str2[i][0]-'0')+(str2[i][1]-'0');
//		a[i][1]=10*(str2[i][3]-'0')+(str2[i][4]-'0');
//		a[i][2]=10*(str2[i][6]-'0')+(str2[i][7]-'0');
//		b[i][0]=10*(str3[i][0]-'0')+(str3[i][1]-'0');
//		b[i][1]=10*(str3[i][3]-'0')+(str3[i][4]-'0');
//		b[i][2]=10*(str3[i][6]-'0')+(str3[i][7]-'0');
		a[i][0]=10*(str[2][i][0]-'0')+(str[2][i][1]-'0');
		a[i][1]=10*(str[2][i][3]-'0')+(str[2][i][4]-'0');
		a[i][2]=10*(str[2][i][6]-'0')+(str[2][i][7]-'0');
		b[i][0]=10*(str[3][i][0]-'0')+(str[3][i][1]-'0');
		b[i][1]=10*(str[3][i][3]-'0')+(str[3][i][4]-'0');
		b[i][2]=10*(str[3][i][6]-'0')+(str[3][i][7]-'0');
		A[i]=a[i][0]*3600+a[i][1]*60+a[i][2];
		B[i]=b[i][0]*3600+b[i][1]*60+b[i][2];
		if (A[i]<min) {
			min = A[i];
			ID1 = str[1][i];
		}
		if (B[i]>max) {
			max = B[i];
			ID2 = str[1][i];
		}
//		printf("%d %d\n",A[i],B[i]);
	}

	printf("%s %s",ID1,ID2);
//	printf("%s %s %s\n",str1[0],str2[0],str3[0]);
	for (i=0; i<m; i++) {
		free(str[1][i]);
		free(str[2][i]);
		free(str[3][i]);
	}

	return 0;
}
