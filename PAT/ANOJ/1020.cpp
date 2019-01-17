#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

const int maxn = 1e3 + 10;
struct node{
	int v, dis;
	node(int _v, int _dis): v(_v), dis(_dis){}
};
vector<node> g[maxn];
int n, m;
int ve[maxn], vl[maxn], inDegree[maxn], outDegree[maxn];
stack<int> topo;
bool topological(int st){
	memset(ve, 0, sizeof(ve));
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topo.push(u);
		for(int i = 0; i < g[u].size(); ++i){
			int v = g[u][i].v, dis = g[u][i].dis;
			ve[v] = max(ve[v], ve[u] + dis);
			if(--inDegree[v] == 0)
				q.push(v);
		}
	}
	if(topo.size() != n + 2)	return false;
	return true;
}

void findPath(int ed){
	fill(vl, vl + maxn, ve[ed]);
	while(!topo.empty()){
		int u = topo.top();
		topo.pop();
		for(int i = 0; i < g[u].size(); ++i){
			int v = g[u][i].v, dis = g[u][i].dis;
			vl[u] = min(vl[u], vl[v] - dis);
		}
	}
}

bool cmp(node a, node b){
	return a.v < b.v;
}

vector<int> ans;
void print(int index, int ed){
	if(index == ed){
		for(int i = 1; i < ans.size(); ++i){
			if(i != 1)	printf("->");
			printf("%d", ans[i]);
		}
		printf("\n");
		return;
	}
	ans.push_back(index);
	sort(g[index].begin(), g[index].end(),cmp);
	for(int i = 0; i < g[index].size(); ++i){
		int v = g[index][i].v, dis = g[index][i].dis;
//		cout << index << " " << v << " " << ve[index] << " " << vl[v] << " " << dis << endl;
		if(ve[index] == vl[v] - dis)
			print(v, ed);	
	}
	ans.pop_back();
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		g[u].push_back(node{v, dis});
		++inDegree[v];
		++outDegree[u];
	}
	int st = 1000, ed = 1001;
	for(int i = 0; i < n; ++i){
		if(inDegree[i] == 0){
			g[st].push_back(node{i, 0});
			++inDegree[i];
			++outDegree[st];
		}
		if(outDegree[i] == 0){
			g[i].push_back(node{ed, 0});
			++inDegree[ed];
			++outDegree[i];
		}
	}
	if(!topological(st)){
		printf("NO %d\n", n + 1 - topo.size());
	}else{
		findPath(ed);
		printf("YES %d\n", ve[ed]);
		print(st, ed);
	}
	return 0;
}
