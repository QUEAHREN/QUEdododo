#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 40

int N;
int preSeq[MAXN], inSeq[MAXN];
int count = -1;
int stack [MAXN];

struct node {
	int data;
	node* lchild;
	node* rchild;
};

node* createNode(int preL, int preR, int inL, int inR) {
	
	if (inL > inR)	return NULL;
	
	node* root = new node;
	root->data = preSeq[preL];
	
	int k;
	for (int i = inL; i <= inR; i ++) if (preSeq[preL] == inSeq[i]){
		k = i;
		break;
	}
	
	root->lchild = createNode(preL+1, preL+k-inL, inL, k-1);
	root->rchild = createNode(preL+k-inL+1, preR, k+1, inR);
	return root;
}

int con = 0;
void postOrder(node* root) {
	
	if (root == NULL)	return ;
	
	postOrder(root->lchild);
	postOrder(root->rchild);
	cout << root->data;	
	con ++;
	if (con < N) cout << " ";
	
	return ;
}


int main(){
	
	cin >> N;
	string op;
	int num;
	int j = 0, k = 0;
	for (int i = 0; i < 2*N; i ++) {
		cin >> op;
		if (op == "Push"){
			cin >> num;
			stack[++ count] = num;
			preSeq[j ++] = num;
		}
		else inSeq[k ++] = stack[count --];
	}	
	
	node* root = new node;
	root = createNode(0, N-1, 0, N-1);
	postOrder(root);
	
	return 0;
}
