//建树版本
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<ctime>
using namespace std;

const int maxn = 1e5 + 10;
unordered_map<int, bool> h;
int pre[maxn];
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

node* lca(node* root, int u, int v){
	while(root != NULL){
		if(root->data < u && root->data < v)
			root = root->right;
		else if(root->data > u && root->data > v)
			root= root->left;
		else break;
	}
	return root;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", pre + i);
		h[pre[i]] = true;
	}
	node* index = creat(0, n - 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		if(!(h[u] && h[v])){
			if(!h[u] && !h[v])
				printf("ERROR: %d and %d are not found.\n", u, v);
			else if(!h[u])
				printf("ERROR: %d is not found.\n", u);
			else
				printf("ERROR: %d is not found.\n", v);
			continue;	
		}
		node* root = lca(index, u, v);
		if(root->data == u){
			printf("%d is an ancestor of %d.\n", u, v);
		}else if(root->data == v){
			printf("%d is an ancestor of %d.\n", v, u);
		}else{
			printf("LCA of %d and %d is %d.\n", u, v, root->data);
		}
	}
	cout << clock() << endl;
	return 0;
} 

//迭代版本 
//迭代版本超时原因是要对每次查询都重新建树 
#include<iostream>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;

const int maxn = 1e5 + 10;
map<int, bool> h;
int pre[maxn];
int m, n;

int lca(const int& u, const int& v){
	int left = 0, right = n - 1;
	while(left <= right){
		int mid;
		for(mid = left + 1; mid <= right; ++mid)
			if(pre[mid] >= pre[left])	break;
		if(mid > right)
		if(pre[left] < u && pre[left] < v)
			left = mid;
		else if(pre[left] > u && pre[left] > v){
			right = mid - 1;
			++left;
		}else{
			break;
		}		
	}
	return pre[left];	
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", pre + i);
		h[pre[i]] = true;
	}
	for(int i = 0; i < m; ++i){ 
		int u, v;
		scanf("%d%d", &u, &v);
		if(!(h[u] && h[v])){
			if(!h[u] && !h[v])
				printf("ERROR: %d and %d are not found.\n", u, v);
			else if(!h[u])
				printf("ERROR: %d is not found.\n", u);
			else
				printf("ERROR: %d is not found.\n", v);
			continue;	
		}
		int root = lca(u, v);
		if(root == u){
			printf("%d is an ancestor of %d.\n", u, v);
		}else if(root == v){
			printf("%d is an ancestor of %d.\n", v, u);
		}else{
			printf("LCA of %d and %d is %d.\n", u, v, root);
		}
	}
	cout << clock() << endl;
	return 0;
}
