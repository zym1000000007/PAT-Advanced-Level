#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Tree {
	int id;
	struct _Tree *left,*right;
} Tree;

typedef struct _Node {
	char *name;
	struct _Node *left,*right;
	struct _Tree *tree;
//	struct _Node b;//¨®D¨º2?¡ä¨®¡ã?¨¬¡ê??a¨º2?¡ä¡¤??¡ã???¨ª3?¡ä¨ª¡ê??a¦Ì¨¤¨¢?¡ê??a?¨´?¨¢?¨¤?-?¡¤¨¢?
} Node;

Tree* addT(Tree *root,int id) {
//	printf("k=%d name=%s\n",k,name);
	if (root) {
		if (root->id > id) {
			root->left = addT(root->left,id);
		} else if (root->id < id) {
			root->right = addT(root->right,id);
		}
	} else {
		root = (Tree*)malloc(sizeof(Tree));
		root->left = NULL;
		root->right = NULL;
		root->id = id;
//		printf("id=%d\n",id);
	}

	return root;
}

int cmp(char *a,char *b) {
	return strcmp(a,b);
}

Node* add(Node *root,char *name,int id) {
//	printf("k=%d name=%s\n",k,name);
	if (root) {
		if (cmp(root->name,name) > 0) {
			root->left = add(root->left,name,id);
		} else if (cmp(root->name,name) < 0) {
			root->right = add(root->right,name,id);
		} else {
			root->tree = addT(root->tree,id);
		}
	} else {
		root = (Node*)malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->name = (char*)malloc(100*sizeof(char));
		strcpy(root->name,name);
//		printf("name=%s\n",name);
		root->tree = NULL;
		root->tree = addT(root->tree,id);
	}

	return root;
}

void inorderT(Tree *root) {
	if (root) {
		inorderT(root->left);
		printf("%07d\n",root->id);
		inorderT(root->right);
	}
}

Node* search(Node *root,char *name) {
	Node *p = NULL;
	if (root) {
		if (cmp(root->name,name) == 0) {
			p = root;
		} else if (cmp(root->name,name) > 0) {
			p = search(root->left,name);
		} else if (cmp(root->name,name) < 0) {
			p = search(root->right,name);
		}
	}
	return p;
}

int main(void) {
	int i,j,n,id,m,type;
	char title[100];
	char c;
	Node *root[6];
	Node *p;

	for (i=0; i<6; i++) {
		root[i] = NULL;
	}
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&id);
		for (j=1; j<3; j++) {
			scanf("\n");
			scanf("%[^\n]",title);
			root[j] = add(root[j],title,id);
		}
		scanf("%c",&c);
		do {
			scanf("%s",title);
			root[j] = add(root[j],title,id);
			scanf("%c",&c);
		} while (c != '\n');
		for (j=4; j<6; j++) {
			if (j > 4)
				scanf("\n");
			scanf("%[^\n]",title);
			root[j] = add(root[j],title,id);
		}
	}

	scanf("%d",&m);
	for (i=0; i<m; i++) {
		scanf("%d: %[^\n]",&type,title);
		printf("%d: %s\n",type,title);
		p = search(root[type],title);
		if (p) {
			inorderT(p->tree);
		} else {
			printf("Not Found\n");
		}
	}

	return 0;
}
