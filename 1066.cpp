#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int key,height;
	struct _Node *left,*right;
} Node;

int MAX(int x,int y) {
	if (x > y) {
		return x;
	} else {
		return y;
	}
}

int HEIGHT(Node* root) {
	if (root) {
		return root->height;
	} else {
		return 0;
	}
}

Node* ll(Node* root) {
	Node* p;
	p = root->left;
	root->left = p->right;
	p->right = root;

	root->height = MAX(HEIGHT(root->left),HEIGHT(root->right)) + 1;
	p->height = MAX(HEIGHT(p->left),root->height) + 1;
	return p;
}

Node* rr(Node* root) {
	Node* p;
	p = root->right;
	root->right = p->left;
	p->left = root;

	root->height = MAX(HEIGHT(root->left),HEIGHT(root->right)) + 1;
	p->height = MAX(HEIGHT(p->right),root->height) + 1;
	return p;
}

Node* lr(Node* root) {
	root->left = rr(root->left);
	return ll(root);
}

Node* rl(Node* root) {
	root->right = ll(root->right);
	return rr(root);
}

Node* add(Node* root,int key) {
	if (root) {
		if (key < root->key) {
			root->left = add(root->left,key);
			if (HEIGHT(root->left) - HEIGHT(root->right) == 2) {
				if (key < root->left->key) {
					root = ll(root);
				} else {
					root = lr(root);
				}
			}
		} else {
			root->right = add(root->right,key);
			if (HEIGHT(root->right) - HEIGHT(root->left) == 2) {
				if (key < root->right->key) {
					root = rl(root);
				} else {
					root = rr(root);
				}
			}
		}
	} else {
		root = (Node*)malloc(sizeof(Node));
		root->key = key;
		root->left = NULL;
		root->right = NULL;
	}
	root->height = MAX(HEIGHT(root->left),HEIGHT(root->right)) + 1;
	return root;
}

int main(void) {
	int i,j,n,key;
	Node *root = NULL;

	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&key);
		root = add(root,key);
//		printf("%d %d\n",key,root->key);
	}
	printf("%d\n",root->key);

	return 0;
}
