#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> pre;
vector<bool> h;
struct node{
	int data;
	node *left, *right;
	node(int _data){
		data = _data;
		left = right = NULL;
	}
};

void insert(node*& root, int data){
	if(root == NULL){
		root = new node(data);
		return;
	}
	if(data < root->data){
		insert(root->left, data);
	}else{
		insert(root->right, data);
	}
}

node* creat(){
	node* root = NULL;
	for(int i = 0; i < n; ++i){
		insert(root, pre[i]);
	}
	return root;
}

bool flag;
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		if(flag)	printf(" ");
		flag = true;
		printf("%d", top->data);
		if(top->left != NULL)
			q.push(top->left);
		if(top->right != NULL)
			q.push(top->right);
	}
}

int main(){
	scanf("%d", &n);
	pre.resize(n);
	h.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &pre[i]);
	}
	node* root = creat();
	BFS(root);
	return 0;
}