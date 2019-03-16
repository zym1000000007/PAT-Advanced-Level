#include <stdio.h>

int plan[101],yes,m;

void solution(int* a,int Need,int value) {
	int i,need;
	if (value <= Need) {
		plan[value] = Need / value;
		for (i=0; i<=a[value]; i++) {
			a[value] -= i;
			if (plan[value] > a[value]) {
				plan[value] = a[value];
			}
//			printf("need=%d value=%d plan=%d a=%d\n",Need,value,plan[value],a[value]);
			need = Need - plan[value] * value;
			if (need == 0) {
				yes = 1;
				break;
			} else if (need > value) {
				solution(a,need,value+1);
				if (yes) {
					break;
				}
			}
			a[value] += i;
		}
	}
}

int main(void) {
	int i,j,n,x,head;

	scanf("%d%d",&n,&m);
	int a[m+1];
	for (i=1; i<=m; i++) {
		a[i] = 0;
	}
	for (i=0; i<n; i++) {
		scanf("%d",&x);
		if (x <= m) {
			a[x]++;
		}
	}
//	for (i=1; i<=m; i++) {
//		printf("i=%d a=%d\n",i,a[i]);
//	}
	for (i=1; i<=m; i++) {
		j = (m+i-1) / i;
		if (a[i] > j) {
			a[i] = j;
		}
	}
//	for (i=0; i<=a[1]; i++) {
//		a[1] -= i;
	solution(a,m,1);
//		a[1] += i;
//		if (yes) {
//			break;
//		}
//	}
	head = 1;
	if (yes) {
		for (i=1; i<=m; i++) {
			if (plan[i] > 0) {
				for (j=0; j<plan[i]; j++) {
					if (head == 1) {
						head = 0;
					} else {
						printf(" ");
					}
					printf("%d",i,plan[i]);
				}
			}
//			printf("i=%d %d\n",i,plan[i]);
		}
	} else {
		printf("No Solution");
	}
//	printf("!!!");

	return 0;
}
