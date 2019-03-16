#include <stdio.h>
#include <stdlib.h>

int I;

struct _root {
	int a;
	int le;
	int sq;
} R[30];

void sort(int k);
void root(const int b[],int lenb,const int c[],int level);

int main(void) {
	int i,j,n,b[30],c[30],lenb;

	I=0;
	scanf("%d",&n);
	lenb=n;
	for (i=0; i<n; i++) {
		scanf("%d",&c[i]);
	}
	for (i=0; i<n; i++) {
		scanf("%d",&b[i]);
	}
	root(b,lenb,c,1);

//	printf("\n%3d",R[0].a);
//	for (i=1; i<n; i++) {
//		printf(" %3d",R[i].a);
//	}
//	printf("\n%3d",R[0].le);
//	for (i=1; i<n; i++) {
//		printf(" %3d",R[i].le);
//	}
	sort(n);
	printf("%d",R[0].a);
	for (i=1; i<n; i++) {
		printf(" %d",R[i].a);
	}
//	printf("\n%3d",R[0].le);
//	for (i=1; i<n; i++) {
//		printf(" %3d",R[i].le);
//	}

	return 0;
}

void sort(int k) {
	int i,j;
	struct _root a1;

	for (i=0; i<k; i++) {
		for (j=i; j<k; j++) {
			if (R[i].le > R[j].le) {
				a1 = R[i];
				R[i] = R[j];
				R[j] = a1;
			} else if ((R[i].le == R[j].le) && (R[i].sq > R[j].sq)) {
				a1 = R[i];
				R[i] = R[j];
				R[j] = a1;
			}
		}
	}
}

void root(const int b[],int lenb,const int c[],int level) {
	int i,k,bb[30],cc[30],lenbb;

//	for (i=0;i<lenb;i++){
//		printf("%d ",b[i]);
//	}
//	printf("\n");
//	for (i=0;i<lenb;i++){
//		printf("%d ",c[i]);
//	}
//	printf("\n");
	R[I].a=c[lenb-1];
	R[I].le=level;
	R[I].sq=0;
	for (i=0; i<I; i++) {
		if (R[i].le == level) {
			R[I].sq++;
		}
	}
	//?¨²b?D?¨°3?a[i]¡ê??¡ä?¨´¡ê?¨¨?o¨®¡ã???¡Á¨®¡À?o¨ª¨®¨°¡À?¨ºy¡Á¨¦??3?3¡è?¨¨¡ê??¨²c?D¨¨?3?o¨®¨¤¨²¡ê?¡¤?¡Àe¦Ì¡Â¨®?root
	for (i=0; i<lenb; i++) {
		if (b[i] == R[I].a) {
			k = i;
			i=lenb;
		}
	}
	I++;
//	printf("%d a=%d k=%d\n",c[lenb-1],R[I-1].a,k);
	for (i=0; i<k; i++) {
		bb[i]=b[i];
		cc[i]=c[i];
	}
	lenbb = k;
//	system("pause");
	if (lenbb > 0)
		root(bb,lenbb,cc,level+1);

	for (i=k+1; i<lenb; i++) {
		bb[i-k-1]=b[i];
		cc[i-k-1]=c[i-1];
	}
	lenbb = lenb - k - 1;
	if (lenbb > 0)
		root(bb,lenbb,cc,level+1);
}
