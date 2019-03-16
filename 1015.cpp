#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int radix(int,int);
bool prime(int number);

int main(void) {
	int i,j,n,d,num;

	scanf("%d",&n);
	j=0;
	while (n >= 0) {
		scanf("%d",&d);

		num = radix(n,d);
		if (j == 1) {
			printf("\n");
		}
		if ((prime(n)) && (prime(num))) {
			printf("Yes");
		} else {
			printf("No");
		}

		j=1;
		scanf("%d",&n);
	}
//	i=radix(23,2);
//	printf("%d",i);

	return 0;
}

int radix(int number,int r1) {
	int i,j,rest,a[100];

	i=0;
	if (number == 0) {
		i=1;
		a[0] = 0;
	} else {
		rest = number;
		while (rest > 0) {
			a[i] = rest % r1;
			rest = rest / r1;
//		printf("%d ",a[i]);
			i++;
		}
	}
	rest = 0;
	for (j=0; j<i; j++) {
		rest += a[j] * pow(r1,i-j-1);
	}
//	printf("rest=%d",rest);

	return rest;
}

bool prime(int number) {
	bool yes=true;
	int i;

	if ((number == 0) || (number == 1)) {
		yes = false;
	} else {
		for (i=2; i<=(sqrt(number)); i++) {
			if ((number % i) == 0) {
				yes = false;
			}
		}
	}
//	printf("yes=%d\n",yes);

	return yes;
}
