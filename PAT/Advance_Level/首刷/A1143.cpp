#include<iostream>
#include<vector>
using namespace std;

vector<int> pre, su, sv;
int m, n;
struct node{
	int data;
	node *left, *right;
	node(int x):data(x){}
};

node* creat(int L, int R){
	if(L > R)	return NULL;
	node* root = new node(pre[L]);
	int mid;
	for(mid = L + 1; mid <= R; ++mid){
		if(pre[mid] >= pre[L])
			break;
	}
	root->left = creat(L + 1, mid - 1);
	root->right = creat(mid, R);
	return root;
}

bool search(node* root, int data, vector<int> &a){
	while(root != NULL && root->data != data){
		a.push_back(root->data);
		if(data < root->data)	root = root->left;
		else	root = root->right;
	}
	if(root == NULL)	return false;
	a.push_back(root->data);
	return true;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		pre.push_back(temp);
	}
	node* root = creat(0, n - 1);
	for(int i = 0; i < m; ++i){
		int u, v, lca;
		su.clear();
		sv.clear();
		scanf("%d%d", &u, &v);
		bool fu = search(root, u, su);
		bool fv = search(root, v, sv);
		if(fu == false || fv == false){
			if(fu == false && fv == false)
				printf("ERROR: %d and %d are not found.\n", u, v);
			else if(fu == false)
				printf("ERROR: %d is not found.\n", u);
			else
				printf("ERROR: %d is not found.\n", v);
			continue;
		}
		for(int j = 0; j < su.size() && j < sv.size(); ++j){
			lca = su[j];
			if(su[j] != sv[j]){
				lca = su[j - 1];
				break;	
			}
		}
		if(u == lca)
			printf("%d is an ancestor of %d.\n", u, v);
		else if(v == lca)
			printf("%d is an ancestor of %d.\n", v, u);
		else
			printf("LCA of %d and %d is %d.\n", u, v, lca);
	}
	return 0;
}
