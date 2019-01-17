#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dis;
int n, m;

int main(){
	scanf("%d", &n);
	dis.resize(n + 1);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &dis[i]);
		dis[i] += dis[i - 1];
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;--v;
		if(u > v)	swap(u, v);
		int d1 = dis[v] - dis[u];
		int d2 = dis[n] - dis[v] + dis[u];
		printf("%d\n", min(d1, d2));
	}
	return 0;
}
