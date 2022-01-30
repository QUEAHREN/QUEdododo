#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
#define MAXN 40

struct node {
	int data;
	node* lchild;
	node* rchild;
};

int N;
int postSeq[MAXN], inSeq[MAXN];

node* createNode(int postL, int postR, int inL, int inR) {
	
	
	if (inL > inR)		return NULL;
	
	node* root = new node;	
	root->data = postSeq[postR];
	
	int k;
	for (int i = inL; i <= inR; i ++)	if (inSeq[i] == postSeq[postR]){
		k = i;
		break;
	}

	root->lchild = createNode(postL, postL+k-inL-1, inL, k-1);
	root->rchild = createNode(postL+k-inL, postR-1, k+1, inR);
	
	return root;
	
} 

//œ»–Ú ‰≥ˆ 
void preOrder(node* root) {
	
	if (root == NULL)	return ;

	cout << root->data;
	preOrder(root->lchild);
	preOrder(root->rchild);
	
	return ;
	
} 

int count = 0;
void BFS(node* root) {
	
	queue<node*> nq;
	nq.push(root);
	
	node* out = new node;
	while(!nq.empty()) {
		
		out = nq.front();
		nq.pop();
		count ++;
		cout << out->data;
		if (count < N)	cout << " ";	
		
		if (out->lchild != NULL)	nq.push(out->lchild);
		if (out->rchild != NULL)	nq.push(out->rchild);
		
	}
	
	return ;
	
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i ++)	cin >> postSeq[i];
	for (int i = 0; i < N; i ++)	cin >> inSeq[i];
	
	node* root = new node;
	root = createNode(0, N-1, 0, N-1);
	
//	preOrder(root);
	BFS(root);
	
	return 0;
	
}
