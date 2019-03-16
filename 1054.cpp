#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//int color[(int)pow(2,24)];
int color[16777216];

int main(void) {
	int N,n,m,i,d,max;

	scanf("%d%d",&m,&n);
	N = n*m;
	for (i=0; i<N; i++) {
		scanf("%d",&d);
		color[d]++;
		if (color[d] > N/2) {
			max = d;
			break;
		}
	}

	printf("%d",max);

	return 0;
}
