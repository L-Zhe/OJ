#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> g[maxn];
double p[maxn];
vector<int> retail;
int n;
double price, t; 

void BFS(int root){
	queue<int> q;
	q.push(root);
	p[root] = price;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < g[u].size(); ++i){
			int v = g[u][i];
			p[v] = p[u] * (1 + t / 100);
			q.push(v);
		}
	}
}

int main(){
//	freopen("data.txt", "r", stdin);
	scanf("%d%lf%lf", &n, &price, &t);
	int num, v;
	for(int i = 0; i < n; ++i){
		scanf("%d", &num);
		if(num == 0)	retail.push_back(i);
		for(int j = 0; j < num; ++j){
			scanf("%d", &v);
			g[i].push_back(v);
		}
	}
	BFS(0);
	int cnt = 0;
	double MIN = 1e10 + 10;
	for(int i = 0; i < retail.size(); ++i){
		int index = retail[i];
		if(p[index] < MIN){
			MIN = p[index];
			cnt = 1;
		}else if(p[index] == MIN){
			++cnt;
		}
	}
	printf("%.4f %d", MIN, cnt);
	return 0;
}
