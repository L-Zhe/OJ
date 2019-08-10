#include<iostream>
#include<queue>
using namespace std;

const int maxn = 510;
int n, m;
int d[maxn], g[maxn][maxn];
bool inq[maxn];

void bfs(int st){
	queue<int> q;
	q.push(st);
	inq[st] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 1; v <= n; ++v){
			if(!inq[v] && g[u][v]){
				inq[v] = true;;
				q.push(v);
			}
		}
	}
}

bool BFS(){
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(!inq[i]){
			bfs(i);
			++cnt;
		}
	}
	if(cnt > 1)	return false;
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
		++d[u];
		++d[v];
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(i != 1)	printf(" ");
		printf("%d", d[i]);
		if(d[i] & 1)	++cnt;
	}
	printf("\n");
	bool flag = BFS();
	if(cnt == 0 && flag)	printf("Eulerian");
	else if(cnt == 2 && flag)	printf("Semi-Eulerian");
	else printf("Non-Eulerian");
	return 0;
}
