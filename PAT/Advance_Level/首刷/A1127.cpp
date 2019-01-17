#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 40;
vector<int> in, post,layer;
int num[maxn];
int n;
struct node{
	int data, layer;
	node *left, *right;
};

node* creat(int inL, int inR, int postL, int postR){
	if(postR < postL)
		return NULL;
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k = inL; k <= inR; ++k){
		if(in[k] == post[postR])
			break;
	}
	int numleft = k - inL;
	root->left = creat(inL, k - 1, postL, postL + numleft - 1);
	root->right = creat(k + 1, inR, postL + numleft, postR - 1);
	return root;
}

void BFS(node* root){
	queue<node*> q;
	root->layer = 1;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		layer.push_back(temp->data);
		num[temp->layer]++;
		if(temp->left != NULL){
			temp->left->layer = temp->layer + 1;
			q.push(temp->left);
		}
			
		if(temp->right != NULL){
			temp->right->layer = temp->layer + 1;
			q.push(temp->right);
		}
	}
}

int main(){
	freopen("data.txt", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		in.push_back(temp);
	}
	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		post.push_back(temp);
	}
	node* root = creat(0, n - 1, 0, n - 1);
	BFS(root);
	cout << layer[0];
	int i = 2;
	int index = 1;
	bool flag = false;
	while(num[i] > 0){
		if(flag)	reverse(layer.begin() + index, layer.begin() + index + num[i]);
		for(int j = 0; j < num[i]; ++j)
			cout << " " << layer[j + index];
		index = num[i] + index;
		++i;
		flag = !flag;
	}
	return 0;
}