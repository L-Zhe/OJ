#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<ctime>
using namespace std;

const int maxn = 3e5 + 10;
struct node{
	int st, ed;
};
bool h[maxn];
node ans[maxn];
int pre[maxn], in[maxn];
int m, n;
int cnt = 0;

void preOrder(int preL, int preR, int inL, int inR){
	if(preL > preR)	return;
	int mid;
	for(mid = inL; mid <= inR; ++mid){
		if(in[mid] == pre[preL])
			break;
	}
	int index = pre[preL];
	int leftNum = mid - inL;
	int st = cnt++;
	preOrder(preL + 1, preL + leftNum, inL, mid - 1);
	preOrder(preL + leftNum + 1, preR, mid + 1, inR);
	int ed = cnt++;
	ans[index].st = st;
	ans[index].ed = ed;
}

int lca(int u, int v){
	int MIN, minr = cnt + 1, minl = -1;
	for(int i = 0; i < n; ++i){
	  int index = pre[i];
		int st = ans[index].st, ed = ans[index].ed;
		if(st <= ans[u].st && st <= ans[v].st && ed >= ans[u].ed && ed >= ans[v].ed){
			if(st > minl && ed < minr){
				minl = st;
				minr = ed;
				MIN = index;
			}
		}
	}
	return MIN;
}

int main(){
//	freopen("data.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", in + i);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", pre + i);
		h[pre[i]] = true;
	}
	preOrder(0, n - 1, 0, n - 1);
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
	return 0;
} 
