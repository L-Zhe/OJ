#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 1010;
int g[maxn][maxn];
int n, m, k;
bool vis[maxn];

void BFS(int u){
	queue<int> q;
	q.push(u);
	vis[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i = 1; i <= n; ++i){
			if(g[v][i] == 1 && !vis[i]){
				q.push(i);
				vis[i] = true;	
			}
		}
	}
}

int cnt(int u){
	memset(vis, 0, sizeof(vis));
	vis[u] = true;
	int count = 0;
	for(int i = 1; i<= n; ++i){
		if(!vis[i]){
			++count;
			BFS(i);
		}
	}
	return count - 1;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	for(int i = 0; i < k; ++i){
		int u;
		scanf("%d", &u);
		printf("%d\n", cnt(u));
	}
}
