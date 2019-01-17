#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 1e3 + 10;
struct node{
	int data, layer;
	node *left, *right;
	node(int _data){
		data = _data;
		left = right = NULL;
	}
};
int a[maxn], n;

void insert(node*& root, int data){
	if(root == NULL){
		root = new node(data);
		return;
	}
	if(data <= root->data){
		insert(root->left, data);
	}else{
		insert(root->right, data);
	}
}


node* creat(){
	node* root = NULL;
	for(int i = 0; i < n; ++i){
		insert(root, a[i]);
	}
	return root;
}

vector<node*> ans;
int maxL = 0, n1 = 0, n2 = 0;
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	root->layer = 1;
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		if(top->layer > maxL)	maxL = top->layer;
		ans.push_back(top);
		if(top->left != NULL){
			top->left->layer = top->layer + 1;
			q.push(top->left);
		}
		if(top->right != NULL){
			top->right->layer = top->layer + 1;
			q.push(top->right);
		}
	}
	for(int i = 0; i < n; ++i){
		if(ans[i]->layer == maxL)	++n1;
		if(ans[i]->layer == maxL - 1)	++n2;
	}
	printf("%d + %d = %d", n1, n2, n1 + n2);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
	}
	node* root = creat();
	BFS(root);
	return 0;
}
