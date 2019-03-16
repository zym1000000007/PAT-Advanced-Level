#include <stdio.h>
#include <math.h>

//int _max(int a,int b);
void sum(int i);

float c[10][5000];
int n[2];
int e[10][5000];

int main(void) {
	int k[10],i,j,max,a;
	float b;

	for (j=0; j<2; j++) {
		scanf("%d%d%f",&k[j],&a,&b);
		c[j][a] = b;
		e[j][a] = a;
		n[j] = a;
		for (i=0; i<k[j]-1; i++) {
			scanf("%d%f",&a,&b);
			c[j][a] = b;
		}
		for (i=0; i<n[j]; i++) {
			e[j][i] = i;
		}
	}

	max = n[0] + n[1];
	int p;
	for (i=0; i<=max; i++) {
		e[3][i]=i;
		c[3][i]=0;
		c[4][i]=0;
	}

	for (i=0; i<=max; i++) {
		sum(i);
	}
//	printf("%d",max);
//	for (i=max; i>=0; i--) {
//		printf(" %d %.1f",e[3][i],c[3][i]);
//	}


	j=0;
	for (i=0; i<=max; i++) {
		if (fabs(c[3][i]) > 0.000001) {
			c[4][j] = c[3][i];
			e[4][j] = e[3][i];
			j++;
		}
	}
	k[3]=j;
	if (k[3] == 0) {
		k[3]=1;
		e[4][0]=0;
		c[4][0]=0.0;
	}

	printf("%d",k[3]);
	for (i=k[3]-1; i>=0; i--) {
		printf(" %d %.1f",e[4][i],c[4][i]);
	}

	return 0;
}

void sum(int i) {
	int j;
	for (j=0; j<=i; j++) {
		if ((j <= n[0]) && ((i-j) <= n[1])) {
			c[3][i] = c[3][i] + c[0][j]*c[1][i-j];
//			if (i==3){
//				printf("j=%d  %f  %f\n",j,c[0][j],c[1][i-j]);
//			}
		}
	}
}

