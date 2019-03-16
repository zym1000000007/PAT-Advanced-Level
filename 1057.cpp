#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lowbit(i) ((i) & (-i))
#define maxn 123456

int tree[maxn];

void update(int x, int v) {
	int i;
	for(i = x; i < maxn; i += lowbit(i))
		tree[i] += v;
}

int getsum(int x) {
	int ans=0,i;
	for(i=x; i>0; i-=lowbit(i))
		ans+=tree[i];
	return ans;
}

//int cmp(const void*a,const void*b) {
//	return *(int*)a - *(int*)b;
//}
//
//int find(int* stack,int n) {
//	int i,st[n];
//
//	for (i=0; i<n; i++) {
//		st[i] = stack[i];
//	}
//
//	qsort(st,n,sizeof(st[0]),cmp);
//
//	return stack[(n+1)/2-1];
//}

int main(void) {
	int i,n,d,top,med,head,left,right,k,mid;
	char str[10];

	scanf("%d",&n);
	int stack[n];

	top = 0;
	head = 1;
	for (i=0; i<n; i++) {
		scanf("%s",str);
		if (strcmp(str,"Push") == 0) {
			scanf("%d",&d);
			stack[top] = d;
//			printf("top=%d stack=%d\n",top,stack[top]);
			top++;
			update(d,1);
		} else if (strcmp(str,"Pop") == 0) {
			if (head == 0) {
				printf("\n");
			} else {
				head = 0;
			}
			if (top > 0) {
				printf("%d",stack[top-1]);
				update(stack[top-1],-1);
				top--;
			} else {
				printf("Invalid");
			}
		} else if (strcmp(str,"PeekMedian") == 0) {
			if (head == 0) {
				printf("\n");
			} else {
				head = 0;
			}
			if (top > 0) {
				k = (top + 1)/2;
				left = 1;
				right = maxn;
				while (left < right) {
					mid = (left + right)/2;
					med = getsum(mid);
					if(med >= k)
						right = mid;
					else if (med < k) {
						left = mid + 1;
					}
//					 else {//???????????,???left=right????????
//						left = mid;
//						break;
//					}
				}
//				med = find(stack,top);
				printf("%d",left);
			} else {
				printf("Invalid");
			}
		}
	}

	return 0;
}
