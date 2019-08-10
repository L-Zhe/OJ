#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
	int data, height;
	node *left, *right;
	node(int _data){
		data = _data;
		left = right = NULL;
		height = 1;
	}
};
int n;

int getHeight(node* root){
	if(root == NULL)	return 0;
	return root->height;
}

void updateHeight(node* root){
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalanceFac(node* root){
	return getHeight(root->left) - getHeight(root->right);
}

void R(node*& root){
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void L(node*& root){
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node*& root, int data){
	if(root == NULL){
		root = new node(data);
		return;
	}
	if(data <= root->data){
		insert(root->left, data);
		updateHeight(root);
		if(getBalanceFac(root) == 2){
			if(getBalanceFac(root->left) == 1){
				R(root);
			}else if(getBalanceFac(root->left) == -1){
				L(root->left);
				R(root);
			}
		}
	}else if(data > root->data){
		insert(root->right, data);
		updateHeight(root);
		if(getBalanceFac(root) == -2){
			if(getBalanceFac(root->right) == -1){
				L(root);
			}else if(getBalanceFac(root->right) == 1){
				R(root->right);
				L(root);
			}
		}
	}
}

node* creat(vector<int> a){
	node* root = NULL;
	for(int i = 0; i < n; ++i)
		insert(root, a[i]);
	return root;
}

bool flag = false;
vector<node*> BFS(node* root){
	queue<node*> q;
	q.push(root);
	vector<node*> ans;
	ans.push_back(NULL);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		if(flag)	printf(" ");
		flag = true;
		printf("%d", top->data);
		ans.push_back(top);
		if(top->left != NULL)	q.push(top->left);
		if(top->right != NULL)	q.push(top->right);
	}
	return ans;
}

bool judge(vector<node*> a){
	for(int i = 1; i <= n / 2; ++i){
		if(2 * i && a[2 * i] != a[i]->left)	return false;
		if(2 * i + 1 <= n && a[2 * i + 1] != a[i]->right)	return false;
	}
	return true;
}

int main(){
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	node* root = creat(a);
	vector<node*> layer = BFS(root);
	printf("\n");
	if(judge(layer))	printf("YES\n");
	else	printf("NO\n");
	return 0;	
}
