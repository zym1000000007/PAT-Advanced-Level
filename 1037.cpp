#include <stdio.h>
#include <stdlib.h>

void sort(int *nc,int n) {
	int i,j;
	int x;

	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			if (nc[i] < nc[j]) {
				x=nc[i];
				nc[i]=nc[j];
				nc[j]=x;
			}
		}
	}
}

int large(const void *a,const void *b) {
	return *(int *)b - *(int *)a;
}

int min(int a,int b) {
	if (a >b) {
		return b;
	} else {
		return a;
	}
}

int main(void) {
	int i,j,NC,NP,NC1,NC2,NP1,NP2,d,k,max=0;
	int nc1[100001],nc2[100001],np1[100001],np2[100001];

	scanf("%d",&NC);
	j=0;
	k=0;
	for (i=0; i<NC; i++) {
		scanf("%d",&d);
		if (d > 0) {
			nc1[j] = d;
			j++;
		} else if (d < 0) {
			nc2[k] = -d;
			k++;
		}
	}
	NC1=j;
	NC2=k;

	j=0;
	k=0;
	scanf("%d",&NP);
	for (i=0; i<NP; i++) {
		scanf("%d",&d);
		if (d > 0) {
			np1[j] = d;
			j++;
		} else if (d < 0) {
			np2[k] = -d;
			k++;
		}
	}
	NP1=j;
	NP2=k;

	qsort(nc1,NC1,sizeof(int),large);
	qsort(nc2,NC2,sizeof(int),large);
	qsort(np1,NP1,sizeof(int),large);
	qsort(np2,NP2,sizeof(int),large);
//	sort(np1,NP1);
//	sort(nc2,NC2);
//	sort(np2,NP2);

	for (i=0; i<min(NC1,NP1); i++) {
		max += nc1[i] * np1[i];
	}
	for (i=0; i<min(NC2,NP2); i++) {
		max += nc2[i] * np2[i];
	}

	printf("%d",max);

	return 0;
}
