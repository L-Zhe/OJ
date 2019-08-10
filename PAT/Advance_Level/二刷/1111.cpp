#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 510;
const int inf = 0x3fffffff;
int dis[maxn][maxn], Time[maxn][maxn];
int d[maxn], t[maxn];
int preD[maxn], preT[maxn];
int n, m, st, ed;
vector<int> ansT, ansD; 

void DijkstraD(int st){
	bool vis[maxn];
	fill(d, d + maxn, inf);
	fill(vis, vis + maxn, false);
	int t[maxn];
	t[st] = 0;
	d[st] = 0;
	for(int i = 0; i < n; ++i){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; ++j){
			if(!vis[j] && d[j] < MIN){
				MIN = d[u = j];
			}
		}
		if(u == -1)	break;
		vis[u] = true;
		for(int v = 0; v < n; ++v){
			if(!vis[v] && dis[u][v] != inf){
				if(d[v] > d[u] + dis[u][v]){
					d[v] = d[u] + dis[u][v];
					t[v] = t[u] + Time[u][v];
					preD[v] = u;
				}else if(d[v] == d[u] + dis[u][v]){
					if(t[v] > t[u] + Time[u][v]){
						t[v] = t[u] + Time[u][v];
						preD[v] = u;	
					}
				}
			}
		}
	}
}

void DijkstraT(int st){
	bool vis[maxn];
	int num[maxn];
	fill(t, t + maxn, inf);
	fill(vis, vis + maxn, false);
	num[st] = 1;
	t[st] = 0;
	for(int i = 0; i < n; ++i){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; ++j){
			if(!vis[j] && t[j] < MIN){
				MIN = t[u = j];
			}
		}
		if(u == -1)	break;
		vis[u] = true;

		for(int v = 0; v < n; ++v){
			if(!vis[v] && Time[u][v] != inf){
				if(t[v] > t[u] + Time[u][v]){
					t[v] = t[u] + Time[u][v];
					num[v] = num[u] + 1;
					preT[v] = u;
				}else if(t[v] == t[u] + Time[u][v]){
					if(num[v] > num[u] + 1){
						num[v] = num[u] + 1;
						preT[v] = u;
					}
				}
			}
		}
	} 
}

void DFS(vector<int>& ans, int a[], int index){
	if(index == st){
		ans.push_back(index);
		return;
	}
	ans.push_back(index);
	DFS(ans, a, a[index]);
}

void print(vector<int> ans){
	for(int i = ans.size() - 1; i >= 0; --i){
		printf(" %d", ans[i]);
		if(i != 0)	printf(" ->");
	}
	printf("\n");
}

int main(){
	fill(dis[0], dis[0] + maxn * maxn, inf);
	fill(Time[0],Time[0] + maxn * maxn, inf);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v, index, D, T;
		scanf("%d%d%d%d%d", &u, &v, &index, &D, &T);
		dis[u][v] = D;
		Time[u][v] = T;
		if(!index){
			dis[v][u] = D;
			Time[v][u] = T;
		}
	}
	scanf("%d%d", &st, &ed);
	DijkstraD(st);
	DijkstraT(st);
	DFS(ansD, preD, ed);
	DFS(ansT, preT, ed);
	if(ansD == ansT){
		printf("Distance = %d; Time = %d:", d[ed], t[ed]);
		print(ansD);
	}else{
		printf("Distance = %d:", d[ed]);
		print(ansD);
		printf("Time = %d:", t[ed]);
		print(ansT);
	}
	return 0;
}
