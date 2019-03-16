#include <stdio.h>

int main(void) {
	int i,j,buy[3];
	float a[3][3],max[3]= {0},profit;
	char game[4]= "WTL";

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			scanf("%f",&a[i][j]);
			if (a[i][j] > max[i]) {
				max[i]=a[i][j];
				buy[i]=j;
			}
		}
	}

	profit = 1;
	for (i=0; i<3; i++) {
		profit = profit * max[i];
		printf("%c ",game[buy[i]]);
	}
	profit = (profit * 0.65 -1) * 2;
	printf("%.2f",profit+0.005);

	return 0;
}
