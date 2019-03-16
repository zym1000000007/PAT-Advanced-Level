#include <stdio.h>
#include <math.h>

int _max(int a,int b);

int main(void) {
	int e[10][2000],k[6],i,j,max;
	float c[10][2000];

	for (j=0; j<2; j++) {
		scanf("%d",&k[j]);
//		printf("k[j]= %d\n",k[j]);
		for (i=0; i<k[j]; i++) {
			scanf("%d%f",&e[j][i],&c[j][i]);
		}
	}

//	printf("a1---k[0]= %d  k[1]= %d\n",k[0],k[1]);
	max = _max(e[0][0],e[1][0]);
	int p;
//	printf("b1---k[0]= %d  k[1]= %d\n",k[0],k[1]);
	for (i=0; i<=max; i++) {
		e[3][i]=i;
		c[3][i]=0;
		c[4][i]=0;
	}
//	printf("a2---k[0]= %d  k[1]= %d\n",k[0],k[1]);
	for (j=0; j<2; j++) {
		p=0;
//		printf("a3---k[0]= %d  k[1]= %d\n",k[0],k[1]);
//		printf("k[j]= %d\n",k[j]);
		while (p<k[j]) {
			c[3][e[j][p]] = c[3][e[j][p]] + c[j][p];
//			printf("c[3][e[j][p]]=%f c[j][p] %f  p=%d\n",c[3][e[j][p]],c[j][p],p);
			p++;
		}
	}
	j=0;
	for (i=0; i<=max; i++) {
		if (fabs(c[3][i]) > 0.000001) {
			c[4][j] = c[3][i];
			e[4][j] = e[3][i];
			j++;
		}
	}
	k[3]=j;
	printf("%d",k[3]);
	for (i=k[3]-1; i>=0; i--) {
		printf(" %d %.1f",e[4][i],c[4][i]);
	}
//	printf("END");
//	printf("%d",k);
//	for (i=0;i<k;i++){
//		printf(" %d %f",e[i],c[i]);
//	}


	return 0;
}

int _max(int a,int b) {
	int max=a;
	if (a<b) {
		max=b;
	}
	return max;
}
