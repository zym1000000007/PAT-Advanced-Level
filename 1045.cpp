#include <stdio.h>

int dp[200+1][10000+1];

int max(int a,int b) {
	int m=a;
	if (b > m) {
		m = b;
	}
	return m;
}

int main(void) {
	int i,j,n,m,k;

	scanf("%d",&k);

	scanf("%d",&n);
	int f[n+1];
	for (i=1; i<=n; i++) {
		scanf("%d",&f[i]);
	}

	scanf("%d",&m);
	int o[m+1];
	for (i=1; i<=m; i++) {
		scanf("%d",&o[i]);
	}

//	int dp[n+1][m+1];
	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if (f[i] == o[j]) {
				dp[i][j]++;
			}
		}
	}

	printf("%d",dp[n][m]);

	return 0;
}
