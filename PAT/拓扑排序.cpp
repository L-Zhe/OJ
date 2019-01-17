/* 
11 16 1 11
1 2 2
1 3 1
2 4 2
2 5 2
3 5 3
3 6 2
4 7 3
5 7 3
5 8 2
6 8 1
7 9 2
7 10 3
8 10 2
8 9 2
9 11 1
10 11 1
 */
#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn  = 1e5 + 10;
struct node{
	int v, w;
};
vector<node> adj[maxn];
stack<int> topOrder;
int ve[maxn], vl[maxn];
int inDegree[maxn];
int n, m, st, ed;

bool topologicalSort(){
	queue<int> q;
	memset(ve, 0, sizeof(ve));
	for(int i = 1; i <= n; ++i){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topOrder.push(u);
		for(int i = 0; i < adj[u].size(); ++i){
			int v = adj[u][i].v, w = adj[u][i].w;
			if(--inDegree[v] == 0)
				q.push(v);
			ve[v] = max(ve[v], ve[u] + w);
 		}
	}
	if(topOrder.size() != n)	return false;
	else	return true;
}

int calPath(){
	if(!topologicalSort())	return -1;
	fill(vl, vl + maxn, ve[ed]);
	while(!topOrder.empty()){
		int u = topOrder.top();
		topOrder.pop();
		for(int i = 0; i < adj[u].size(); ++i){
			int v = adj[u][i].v, w = adj[u][i].w;
			vl[u] = min(vl[u], vl[v] - w);
		}
	}
	return ve[ed];
}

vector<int> path;
void printPath(int u){
	if(u == ed){
		for(int i = 0; i < path.size(); ++i){
			if(i != 0)	printf("->");
			printf("%d", path[i]);
		}
		printf("\n");
	}
	if(u == st)
		path.push_back(u);
	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i].v, w = adj[u][i].w;
		if(ve[u] == vl[v] - w){
			path.push_back(v);
			printPath(v);
			path.pop_back();
		}
	}
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i = 0; i < m; ++i){
		int u;
		node temp;
		scanf("%d%d%d", &u, &temp.v, &temp.w);
		++inDegree[temp.v];
		adj[u].push_back(temp);
	}
	printf("%d\n", calPath());
	printPath(st);
	freopen("Con", "r", stdin);
	system("pause");
	return 0;
}