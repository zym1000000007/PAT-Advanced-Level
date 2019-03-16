#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#define BLOCK 1234

long int PRI[1234567],CNT;//PRI??????,CNT?????????

void create(long int n) {
	long int r,i,j,last;
	if (CNT > 0) {
		last = PRI[CNT-1]+1;
	} else {
		last = 2;
	}
	if (n > last) {
		bool A[n-last+1];
		memset(A, true, sizeof(bool)*(n-last+1));
		for (i=0; i<CNT; i++) {
			r = last % PRI[i];
			if (r > 0) {
				j = last + (PRI[i] - r);
			} else {
				j = last;
			}//j??????????????PRI[i]????
			while (j <= n) {//?PRI[i]???????false
				A[j-last] = false;
				j += PRI[i];
			}
		}

		for (i = last; i*i <=n; i++) {//?????
			if (A[i-last]) {
				j = i*i;
				while (j <= n) {
					A[j-last] = false;
					j += i;
				}
			}
		}
		for (i=last; i<=n; i++) {//????true??,?????,???PRI?
			if (A[i-last]) {
				PRI[CNT++] = i;
			}
		}
	}
}

int main(void) {
	long int i,j,head;
	long int prime[12345],cnt[12345];
	long int n,m;

	scanf("%ld",&m);

	if (m > 1) {
		n = m;
		i = 0;
		PRI[0] = 2;
		CNT = 1;
		while (n > 1) {
			cnt[i] = 0;
			if (i >= CNT) {//???????????????,?????,????BLOCK=1234?????
				create(PRI[CNT-1]+BLOCK);
			}
			prime[i] = PRI[i];
			while ((n % prime[i]) == 0) {//?cnt[i]??????????
				n = n / prime[i];
				cnt[i]++;
			}
			i++;
		}
		//??m??????????????
		j = i;
		printf("%ld=",m);
		head = 1;
		for (i=0; i<j; i++) {
			if (cnt[i] > 0) {//?????????1???
				if (head == 0) {
					printf("*");
				} else {
					head = 0;
				}
				printf("%ld",prime[i]);
				if (cnt[i] > 1) {
					printf("^%ld",cnt[i]);
				}
			}
		}
	} else {
		printf("1=1");
	}

	return 0;
}
