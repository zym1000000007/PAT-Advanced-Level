#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Node {
	char name[12],pass[12];
} Node;

int main(void) {
	int i,j,n,k;
	bool yes;
	char password[12];

//	password[0]='R';
//	password[1]='@';
//	password[2]='\0';
//	printf("%s\n",password);

	scanf("%d",&n);
	Node node[n],node2[n];

	k=0;
	for (i=0; i<n; i++) {
		yes = false;
		scanf("%s%s",node[i].name,node[i].pass);
		for (j=0; j<strlen(node[i].pass); j++) {
			if (node[i].pass[j] == '1') {
				password[j] = '@';
				yes = true;
			} else if (node[i].pass[j] == '0') {
				password[j] = '%';
				yes = true;
			} else if (node[i].pass[j] == 'l') {
				password[j] = 'L';
				yes = true;
			} else if (node[i].pass[j] == 'O') {
				password[j] = 'o';
				yes = true;
			} else {
				password[j] = node[i].pass[j];
			}
		}
		password[j] = '\0';
		if (yes) {
			strcpy(node2[k].name,node[i].name);
			strcpy(node2[k].pass,password);
			k++;
		}
	}

	if (k == 0) {
		if (n == 1) {
			printf("There is 1 account and no account is modified");
		} else {
			printf("There are %d accounts and no account is modified",n);
		}
	} else {
		printf("%d\n",k);
		printf("%s %s",node2[0].name,node2[0].pass);
		for (i=1; i<k; i++) {
			printf("\n%s %s",node2[i].name,node2[i].pass);
		}
	}

	return 0;
}
