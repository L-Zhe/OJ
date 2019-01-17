#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 1e4 + 10;
struct node{
	int u, v;
}edge[maxn];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &edge[i].u, &edge[i].v);
	}
	int k, num;
	bool h[maxn];
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		memset(h, 0, sizeof(h));
		scanf("%d", &num);
		for(int j = 0; j < num; ++j){
			int temp;
			scanf("%d", &temp);
			h[temp] = true;
		}
		bool flag = true;
		for(int j = 0; j < m; ++j){
			int u = edge[j].u, v = edge[j].v;
			if(!h[u] && !h[v])	flag = false;
		} 
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
