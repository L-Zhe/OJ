#include<iostream>
#include<vector>
using namespace std;

struct node{
	int data;
	node *left, *right;
};
bool flag = true;
int n;
vector<int> pre, post, in;

node* creat(int preL, int preR, int postL, int postR){
	if(preL > preR)
		return NULL;
	node* root = new node;
	root->data = pre[preL];
	root->left = root->right = NULL;
	if(preL == preR)
		return root;
	int k;
	for(k = postL; k <= postR - 1; ++k){
		if(post[k] == pre[preL + 1])
			break;
	}
	if(k == postR - 1)
		flag =  false;			//当一棵树只有一个子树时，无法判断是左子树还是右子树 
	int numLeft = k - postL + 1;

	root->left = creat(preL + 1, preL + numLeft, postL, k);
	root->right = creat(preL + numLeft + 1, preR, k + 1, postR - 1);
	return root;
}

void inOrder(node* root){
	if(root == NULL)
		return;
	inOrder(root->left);
	in.push_back(root->data);
	inOrder(root->right);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		pre.push_back(temp);
	}
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		post.push_back(temp);
	}
	node* root = creat(0, n -1, 0, n - 1);
	inOrder(root);
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	for(int i = 0; i < in.size(); ++i){
		if(i != 0)
			printf(" ");
		printf("%d", in[i]);
	}
	
	return 0;
}
