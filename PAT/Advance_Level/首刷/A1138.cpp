#include<iostream>
#include<vector>
using namespace std;

vector<int> pre, in;
struct node{
	int data;
	node *left, *right;
	node(int x):data(x){}
};

node* creat(int preL, int preR, int inL, int inR){
	if(preL > preR)	return NULL;
	node* root = new node(pre[preL]);
	int m;
	for(m = inL; m <= inR; ++m){
		if(in[m] == pre[preL])
			break;
	}
	int numLeft = m - inL;
	root->left = creat(preL + 1, preL + numLeft, inL, m - 1);
	root->right = creat(preL + numLeft + 1, preR, m + 1, inR);
	return root;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		pre.push_back(temp);
	}
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		in.push_back(temp);
	}
	node* root = creat(0, n - 1, 0, n - 1);
	while(root->left != NULL || root->right != NULL){
		if(root->left != NULL)	root = root->left;
		else	root = root->right;
	}
	printf("%d", root->data);
	return 0;
}
