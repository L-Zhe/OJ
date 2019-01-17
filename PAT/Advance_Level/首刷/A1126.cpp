#include<iostream>
#include<queue>
using namespace std;

const int maxn = 510;
int n, m;
int d[maxn], g[maxn][maxn];
bool vis[maxn];

void BFS(int st){
	queue<int> q;
	q.push(st);
	vis[st] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 1; v <= n; ++v){
			if(!vis[v] && g[u][v] == 1){
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		++d[u];
		++d[v];
		g[u][v] = g[v][u] = 1;
	}
	int count = 0;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			BFS(i);
			++count;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(i != 1)	printf(" ");
		printf("%d", d[i]);
		if(d[i] & 1)
			++cnt;
	}
	if(count == 1 && cnt == 0)
		printf("\nEulerian");
	else if(count == 1 && cnt == 2)
		printf("\nSemi-Eulerian");
	else
		printf("\nNon-Eulerian");
	return 0;
}

