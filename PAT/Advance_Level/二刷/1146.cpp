#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1e3 + 10;
vector<int> g[maxn];
int inDegree[maxn], temp[maxn];
int n, m, k;

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		++inDegree[v];
	}
	scanf("%d", &k);
	bool flag = false, judge;
	for(int i = 0; i < k; ++i){
		judge = true;
		for(int j = 1; j <= n; ++j)	temp[j] = inDegree[j];
		for(int j = 0; j < n; ++j){
			int u;
			scanf("%d", &u);
			if(temp[u] != 0)	judge = false;
			for(int index = 0; index < g[u].size(); ++index){
				int v = g[u][index];
				--temp[v];
			}
		}
		if(!judge){
			if(flag)	printf(" ");
			flag = true;
			printf("%d", i);
		}
	}
	return 0;
}

