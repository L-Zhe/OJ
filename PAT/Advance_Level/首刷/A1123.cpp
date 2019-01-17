#include<iostream>
#include<queue>
using namespace std;

struct node{
	int data, height;
	node *left, *right;
	
};
vector<int> layer, ans;
int n;

node* newNode(int x){
	node *Node = new node;
	Node->height = 1;
	Node->left = Node->right = NULL;
	Node->data = x;
	return Node;
}

int getHeight(node* root){
	if(root == NULL)
		return 0;
	return root->height;
}

int getBalanceFac(node* root){
	return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(node* root){
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void R(node* &root){
	node* temp = root->left;
	root->left = temp ->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void L(node* &root){
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x < root->data){
		insert(root->left, x);
		updateHeight(root);
		if(getBalanceFac(root) == 2){
			if(getBalanceFac(root->left) == 1){
				R(root);
			}
			else if(getBalanceFac(root->left) == -1){
				L(root->left);
				R(root);
			}
		}
	}
	else{
		insert(root->right, x);
		updateHeight(root);
		if(getBalanceFac(root) == -2){
			if(getBalanceFac(root->right) == -1){
				L(root);
			}
			else if(getBalanceFac(root->right) == 1){
				R(root->right);
				L(root);
			}
		}
	}
}

void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		layer.push_back(temp->data);
		q.pop();
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
	
}

bool judge(){
	for(int i = 1; i <= n; ++i){
		int left = 2 * i, right = 2 * i + 1;
		if(left <= n && layer[left] >= layer[i])
			return false;
		if(right <= n && layer[right] < layer[i])
			return false;
	}
	return true;
}

int main(){
	cin >> n;
	node* root = NULL;
	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		insert(root, temp);
	}
	BFS(root);
	layer.insert(layer.begin(), 0);
	bool flag = judge();
	layer.erase(layer.begin());
	for(int i = 0; i < n; ++i){
		if(i != 0)	cout << " ";
		cout << layer[i];
	}
	cout << endl;
	
	if(flag)	cout << "YES";
	else	cout << "NO";
	return 0;
}