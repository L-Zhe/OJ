#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int maxn  =1e5 + 10;
vector<int> g[maxn];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < m; ++i){
		int k;
		scanf("%d", &k);
		bool h[maxn];
		memset(h, 0, sizeof(h));
		bool flag = true;
		for(int j = 0; j < k; ++j){
			int temp;
			scanf("%d", &temp);
			h[temp] = true;
			for(int k = 0; k < g[temp].size(); ++k){
				int index = g[temp][k];
				if(h[index]) flag = false;
			}
		}
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
