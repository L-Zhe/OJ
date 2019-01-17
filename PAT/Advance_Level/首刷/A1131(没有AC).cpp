#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 1e4 + 10;
const int inf =0x3fffffff;
int g[maxn][maxn], stop[maxn];
int n, k, st, ed, MIN, MC;
vector<int> ans, temp;
bool vis[maxn];

void DFS(int u, int num, int change){
	if(u == ed){
		if(num < MIN){
			MIN = num;
			MC = change;
			ans = temp;
		}else if(num == MIN && change < MC){
			ans = temp;
			MC = change;
		}
		return;
	}
	for(int v = 0; v < maxn; ++v){
		if(!vis[v] && g[u][v] != 0){
			vis[v] = true;
			bool flag = false;
			if(v != ed && stop[u] != stop[v]){
				++change;
				flag = true;
			}
			temp.push_back(v);
			DFS(v, num + 1, change);
			temp.pop_back();
			if(flag)
				--change;
			vis[v] = false;
		}
	}
}

void print(){
	printf("%d\n", MIN);
	int i = 0;
	vector<int>	road;
	for(int i = 1; i < ans.size(); ++i){
		road.push_back(g[ans[i - 1]][ans[i]]);
	} 
	while(i < ans.size()){
		printf("Take Line#%d from %04d to ", road[i], ans[i]);
		++i;
		while(ans[i] != ed && road[i] == road[i - 1])	++i;
		printf("%04d.\n", ans[i]);
		if(ans[i] == ed)	break;
	}
}

int main(){
 	freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int m, u, v;
		scanf("%d", &m);
		scanf("%d", &u);
		for(int j = 1; j < m; ++j){
			scanf("%d", &v);
			g[u][v] = g[v][u] = i;
			stop[u] = stop[v] = i;
			u = v;
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d%d", &st, &ed);
		MIN = inf;
		MC = inf;
		memset(vis, 0, sizeof(vis));
		temp.clear();
		temp.push_back(st);
		vis[st] = true;
		DFS(st, 0, 0);
				for(int j = 0; j < ans.size(); ++j)
			cout << ans[i] << " ";
		cout << endl;
		print();
	}
	return 0;
}
