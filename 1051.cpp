#include <stdio.h>

int judge(int*,int,int);

int main(void) {
	int i,j,m,n,k;
	int yes;

	scanf("%d%d%d",&m,&n,&k);
	int d[n];
	for (i=0; i<k; i++) {
		if (i > 0) {
			printf("\n");
		}
		for (j=0; j<n; j++) {
			scanf("%d",&d[j]);
		}
		yes = judge(d,m,n);
		if (yes) {
			printf("YES");
		} else {
			printf("NO");
		}
	}

	return 0;
}

int judge(int*d,int m,int n) {
	int i,j,last,k,top;
	int zhai[n];
	int yes=1;

	last = 0;
	k = 0;
	top = 0;
	for (i=0; i<n; i++) {
		if (d[i] < top) {
			yes=0;
			break;
		} else if (d[i] == top) {
			k--;
			if (k > 0)
				top = zhai[k-1];
			else
				top = 0;
			if (d[i] > last)
				last = d[i];
		} else {
			if (d[i] > last) {
				for (j=last+1; j<d[i]; j++) {
					zhai[k] = j;
					k++;
				}
			}  else if (d[i] == last) {
				yes=0;
				break;
			}
//			printf("k=%d\n",k);
			if (k > m-1) {
				yes=0;
				break;
			}
			if (k > 0)
				top = zhai[k-1];
			else
				top = 0;
			if (d[i] > last)
				last = d[i];
		}
	}
	return yes;
}
