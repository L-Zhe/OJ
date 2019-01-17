#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

#define red true
#define black false
const int maxn = 35;
struct node{
	int data;
	bool color;
	node *left, *right;
};
int k, n;
int a[maxn];
bool flag;

node* creat(int left, int right){
	if(left > right)
		return NULL;
	node* root = new node;
	if(a[left] < 0){
		root->color = red;
		a[left] *= -1;
	}else{
		root->color = black;
	}
	root->data = a[left];
	int mid;
	for(mid = left + 1; mid <= right; ++mid){
		if(abs(a[mid]) > abs(a[left]))
			break;
	}
	root->left = creat(left + 1, mid - 1);
	root->right = creat(mid, right);
	return root;
}

int DFS(node* root){
	if(root == NULL)
		return 1;
	int cnt_left = DFS(root->left);
	int cnt_right = DFS(root->right);
	if(cnt_left != cnt_right)	flag = false;
	int num = cnt_left;
	if(root->color == black)	++num;
	return num;
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

void judge(node* root){
	BFS(root);
	DFS(root);
	if(root->color != black)	flag = false;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d", &n);
		for(int j = 0; j < n; ++j){
			scanf("%d", a + j);
		}
		node* root = creat(0, n - 1);
		flag = true;
		judge(root);
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
