#include <stdio.h>
#include <string.h>

int main(void) {
	int i,j,n,k,num1,num2,position,cnt;
	char str[4][100],s[4][100];
	char first[3],second;
	char day[7][10]= {"MON","TUE","WED","THU","FRI","SAT","SUN"};

	for (i=0; i<4; i++) {
		scanf("%s",str[i]);
	}

	cnt = 0;
	for (i=0; i<strlen(str[0]); i++) {
		if ((str[0][i] <= 'G') && (str[0][i] >= 'A')) {
			if (str[1][i] == str[0][i]) {
				first[cnt] = str[0][i];
//				printf("%d %c\n",cnt,first[cnt]);
				cnt++;
				k = i;
			}
		}
		if (cnt == 1) {
			break;
		}
	}
	for (i=k+1; i<strlen(str[0]); i++) {
		if (((str[0][i] <= 'N') && (str[0][i] >= 'A')) || ((str[0][i] >= '0') && (str[0][i] <= '9'))) {
			if (str[1][i] == str[0][i]) {
				first[cnt] = str[0][i];
//			printf("%c\n",first[cnt]);
//				printf("%d %c\n",cnt,first[cnt]);
				cnt++;
				break;
			}
		}
	}

	for (i=0; i<strlen(str[2]); i++) {
		if (((str[2][i] <= 'Z') && (str[2][i] >= 'A')) || ((str[2][i] <= 'z') && (str[2][i] >= 'a'))) {
			if (str[2][i] == str[3][i]) {
				position = i;
//				printf("%d\n",position);
				break;
			}
		}
	}

	num1 = first[0] - 'A';
	second = first[1];
	if ((second >= '0') && (second <= '9')) {
		num2 = second - '0';
	} else {
		num2 = second - 'A' + 10;
	}
	printf("%s %02d:%02d",day[num1],num2,position);

	return 0;
}
