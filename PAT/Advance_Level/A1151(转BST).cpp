#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 3e5 + 10;
bool h[maxn];
int pre[maxn], in[maxn], num[maxn];
int m, n;
int lca(int u, int v){
	for(int i = 0; i < n; ++i){
		int index = pre[i];
		if(num[index] >= min(num[u], num[v]) && num[index] <= max(num[u], num[v]))	
			return index;
	}
}
int main(){
//	freopen("data.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", in + i);
		num[in[i]] = i + 1;		
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", pre + i);
		h[pre[i]] = true;
	}
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		if(!h[u] && !h[v])
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if(!h[u] || !h[v])
			printf("ERROR: %d is not found.\n", !h[u] ? u : v);
		else{
			int root = lca(u, v);
	  		if(root == u || root == v)
	 	 		printf("%d is an ancestor of %d.\n", root == u ? u : v, root == u ? v : u);
		  	else
	 	 		printf("LCA of %d and %d is %d.\n", u, v, root);
		}
	}
	return 0;
}
