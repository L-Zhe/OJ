#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 40;
const int inf = 0x3fffffff;
vector<int> g[maxn];
int n, m, l, cnt;

void DFS(int now, int v, int total){
		if(total == l && now != v)	return;
	if(now == v && total == l){
		cnt = (cnt + 1) % 1000000007;
		return;
	}
	for(int i = 0; i < g[now].size(); ++i){
		int u = g[now][i];
		DFS(u, v, total + 1);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &l);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	int k;
	scanf("%d",  &k);
	for(int i = 0; i < k; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		cnt = 0;
		DFS(u, v, 0);
		printf("%d\n", cnt);
	}
	return 0;
}
