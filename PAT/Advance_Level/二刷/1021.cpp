#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 1e4 + 10;
vector<int> g[maxn];
bool vis[maxn];
int n;
vector<int>	ans;

void bfs(int u){
	queue<int> q;
	q.push(u);
	vis[u] = true;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(int i = 0; i < g[top].size(); ++i){
			int v = g[top][i];
			if(!vis[v]){
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int BFS(int u){
	memset(vis, 0, sizeof(vis));
	int deep;
	int layer[maxn];
	queue<int> q;
	q.push(u);
	vis[u] = true;
	layer[u] = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		deep = layer[top];
		for(int i = 0; i < g[top].size(); ++i){
			int v = g[top][i];
			if(!vis[v]){
				layer[v] = layer[top] + 1;
				q.push(v);
				vis[v] = true;
			}
		}
	}
	return deep;
}

int main(){
	//freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			++cnt;
			bfs(i);
		}
	}
	if(cnt == 1){
		int MAX = 0;
		for(int i = 1; i <= n; ++i){
			int deep = BFS(i);
			if(deep > MAX){
				MAX = deep;
				ans.clear();
				ans.push_back(i);
			}else if(deep == MAX){
				ans.push_back(i);
			}
		}
		for(int i = 0; i < ans.size(); ++i){
			printf("%d\n" ,ans[i]);
		}
	}else{
		printf("Error: %d components", cnt);
	}
	return 0;
}
