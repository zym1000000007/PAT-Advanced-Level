#include <stdio.h>

void move(int* card,int* order) {
	int i,j;
	int card2[55];

	for (i=1; i<55; i++) {
		card2[order[i]] = card[i];
	}

	for (i=1; i<55; i++) {
		card[i] = card2[i];
	}
}

void change(char name[55][4],int* card) {
	int i,j,k;

	for (i=1; i<55; i++) {
//		printf("%d\n",card[i]-1 / 13);
		switch ((card[i]-1) / 13) {
			case 0:
				name[i][0] = 'S';
				break;
			case 1:
				name[i][0] = 'H';
				break;
			case 2:
				name[i][0] = 'C';
				break;
			case 3:
				name[i][0] = 'D';
				break;
			case 4:
				name[i][0] = 'J';
				break;
		}
		k = card[i] % 13;
		if (k == 0) k = 13;
		if (k < 10) {
			name[i][1] = k + '0';
			name[i][2] = '\0';
		} else {
			name[i][1] = '1';
			name[i][2] = k - 10 + '0';
			name[i][3] = '\0';
		}
	}
}

int main(void) {
	int i,j,n;
	int card[55],order[55];
	char name[55][4];

	scanf("%d",&n);
	for (i=1; i<55; i++) {
		card[i] = i;
	}

	for (i=1; i<55; i++) {
		scanf("%d",&order[i]);
	}

	for (i=0; i<n; i++) {
		move(card,order);
	}

	change(name,card);

	for (i=1; i<54; i++) {
		printf("%s ",name[i]);
	}
	printf("%s",name[54]);

	return 0;
}
