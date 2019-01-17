#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 35;
int post[maxn], in[maxn];
int n;
vector<int> ans[maxn];
struct node{
	int data, layer;
	node *left, *right;;
	node(int _data){
		data = _data;
		left = right = NULL;
	}
};

node* creat(int inL, int inR, int postL, int postR){
	if(postL > postR)	return NULL;
	node* root = new node(post[postR]);
	int mid;
	for(mid = inL; mid <= inR; ++mid){
		if(in[mid] == post[postR])	break;
	}
	int leftNum = mid - inL;
	root->left = creat(inL, mid - 1, postL, postL + leftNum - 1);
	root->right  = creat(mid + 1, inR, postL + leftNum, postR - 1);
	return root;
}

void BFS(node* root){
	queue<node*> q;
	root->layer = 1;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		ans[top->layer].push_back(top->data);
		if(top->left != NULL){
			top->left->layer = top->layer + 1;
			q.push(top->left);
		}	
		if(top->right != NULL){
			top->right->layer = top->layer + 1;
			q.push(top->right);
		}
	}
	bool flag = false;
	for(int i = 0; i < maxn; ++i){
		if(i & 1){
			for(int j = ans[i].size() - 1; j >= 0; --j){
				if(flag)	printf(" ");
				flag = true;
				printf("%d", ans[i][j]);
			}
		}else{
			for(int j = 0; j < ans[i].size(); ++j){
				if(flag)	printf(" ");
				flag = true;
				printf("%d", ans[i][j]);
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", in + i);
	for(int i = 0; i < n; ++i)
		scanf("%d", post + i);
	node* root = creat(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;	
}
