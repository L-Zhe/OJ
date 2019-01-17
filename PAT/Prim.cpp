int n, g[maxn][maxn];
int d[maxn];
bool vis[maxn] = { false };
int Prim(){
	fill(d, d + maxn, inf);
	d[0] = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; ++j){
			if(vis[j] == false && d[j] < MIN)
				MIN = d[u = j];
		}
		if(u == -1)
			return -1;
		vis[u] = true;
		ans += d[u];
		for(int v = 0; v < n; ++v){
			if(vis[v] == false && g[u][v] != inf && g[u][v] < d[v])
				d[v] = g[u][v];
		}
	}
	return ans;
}