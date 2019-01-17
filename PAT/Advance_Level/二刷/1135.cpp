#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

#define red false
#define black true
const int maxn = 35;
struct node{
	int data;
	node *left, *right;
	bool color;
	node(int _data){
		if(_data < 0)	color = red;
		else	color = black;	
		data = abs(_data);
		left = right = NULL;
	}
};
int k, n;
int pre[maxn];
bool flag;

node* creat(int left, int right){
	if(left > right)	return NULL;
	node* root = new node(pre[left]);
	int mid;
	for(mid = left + 1; mid <= right; ++mid)
		if(abs(pre[mid]) > abs(pre[left]))	break;
	int index;
	for(index = right; index >= left + 1; --index)
		if(abs(pre[index]) < abs(pre[left]))	break;
	if(mid != index + 1)	flag = false;
	root->left = creat(left + 1, mid - 1);
	root->right = creat(mid, right);
	return root;
}

void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		if(top->color == red){
			if(top->left != NULL && top->left->color == red)
				flag = false;
			if(top->right != NULL && top->right->color == red)
				flag = false;
		}
		if(top->left != NULL)	q.push(top->left);
		if(top->right != NULL)	q.push(top->right);
	}
}

int getHeight(node* root){
	if(root == NULL)	return 1;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	if(left != right)	flag = false;
	if(root->color == black)	return left + 1;
	else 	return left;
}

int main(){
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d", &n);
		flag = true;
		for(int j = 0; j < n; ++j){
			scanf("%d", pre + j);
		}
		node* root = creat(0, n - 1);
		if(root->color != black)	flag= false;
		BFS(root);
		getHeight(root);
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
