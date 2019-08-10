#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
bool flag = false;
vector<int> post, in;
struct node{
	int data;
	node *left, *right;
};


node* creat(int postL, int postR, int inL, int inR){
	if(postL > postR)	return NULL;
	node* root = new node;
	root->data = post[postR];
	int mid;
	for(mid = inL; mid <= inR; ++mid){
		if(in[mid] == post[postR])
			break;
	}
	int k = mid - inL;
	root->left = creat(postL, postL + k - 1, inL, mid - 1);
	root->right = creat(postL + k, postR - 1, mid + 1, inR);
	return root;
}

void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		if(flag){
			printf(" ");
		}
		flag = true;
		printf("%d", top->data);
		if(top->left != NULL)	q.push(top->left);
		if(top->right != NULL)	q.push(top->right);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		post.push_back(temp);
	}
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		in.push_back(temp);
	}
	node* root = creat(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}
