#include<iostream>
#include<vector>
using namespace std;

const int maxn = 510;
const int inf = 0x3fffffff;
int g[maxn][maxn], num[maxn], d[maxn];
bool vis[maxn];
int cmax, n, ed, m;
vector<int> pre[maxn], ans, temp;

void Dijkstra(int st){
	fill(d, d + maxn, inf);
	d[st] = 0;
	for(int i = 0; i <= n; ++i){
		int u = -1, MIN = inf;
		for(int j = 0; j<= n; ++j){
			if(!vis[j] && d[j] < MIN)
				MIN = d[u = j];
		}
		if(u == -1)	break;
		vis[u] = true;
		for(int v = 0; v <= n; ++v){
			if(!vis[v] && g[u][v] != inf){
				if(d[v] > d[u] + g[u][v]){
					d[v] = d[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[v] == d[u] + g[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

int MINB = inf, MINC = inf;
void DFS(int u){
	if(u == 0){
		int bring = 0, carry = 0;
		for(int i = temp.size() - 1; i >= 0; --i){
			int v = temp[i];
			if(num[v] > 0)	carry += num[v];
			else{
				int total = carry + num[v];
				if(total < 0){
					bring -= total;
					carry = 0;
				}else{
					carry += num[v];
				}
			}
		}
		if(bring < MINB){
			MINB = bring;
			ans = temp;
			MINC = carry;
		}else if(bring == MINB && carry < MINC){
			MINC = carry;
			ans = temp;
		}
		return;
	}
	if(u == ed)	temp.push_back(u);
	for(int i = 0; i < pre[u].size(); ++i){
		int v = pre[u][i];
		temp.push_back(v);
		DFS(v);
		temp.pop_back();
	}
}

int main(){
//	freopen("data.txt", "r", stdin);
	scanf("%d%d%d%d", &cmax, &n, &ed, &m);
	fill(g[0], g[0] + maxn * maxn, inf);
	for(int i = 1; i <= n; ++i){
		scanf("%d", num + i);
		num[i] -= cmax / 2;		//表示多余的车辆 
	}
	for(int i = 0; i < m; ++i){
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		g[u][v] = g[v][u] = dis;
	}
	Dijkstra(0);
	DFS(ed);
	printf("%d ", MINB);
	for(int i = ans.size() - 1; i >= 0; --i){
		printf("%d", ans[i]);
		if(i != 0)	printf("->");
	}
	printf(" %d", MINC);
	return 0;
}
