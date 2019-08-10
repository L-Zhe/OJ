#include<iostream>
using namespace std;

const int maxn = 510;
const int inf = 0x3fffffff;
int n, m, st, ed;
int g[maxn][maxn], cost[maxn][maxn], pre[maxn], d[maxn], c[maxn];
bool vis[maxn];

void Dijkstra(int st){
	fill(d, d + maxn, inf);
	fill(c, c + maxn, inf);
	d[st] = 0;
	c[st] = 0;
	for(int i = 0; i < n; ++i){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; ++j){
			if(!vis[j] && d[j] < MIN)
				MIN = d[u = j];
		}
		if(u == -1)	break;
		vis[u] = true;
		for(int v = 0; v < n; ++v){
			if(!vis[v] && g[u][v] != inf){
				if(d[v] > d[u] + g[u][v]){
					d[v] = d[u] + g[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}else if(d[v] == d[u] + g[u][v]){
					if(c[v] > c[u] + cost[u][v]){
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}

void print(int u){
	if(u == st){
		printf("%d ", st);
		return;
	}
	print(pre[u]);
	printf("%d ", u);
}

int main(){
	fill(g[0], g[0] + maxn * maxn, inf);
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i = 0; i < m; ++i){
		int u, v, dis, p;
		scanf("%d%d%d%d", &u, &v, &dis, &p);
		g[u][v] = g[v][u] = dis;
		cost[u][v] = cost[v][u] = p;
	}
	Dijkstra(st);
	print(ed);
	printf("%d %d", d[ed], c[ed]);
	return 0;
}
