#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 210;
int nv, ne;
int g[maxn][maxn], degree[maxn];
vector<int> ans;

bool judgeCli(){
	for(int i = 0; i < ans.size() - 1; ++i){
		for(int j = i + 1; j < ans.size(); ++j){
			int u = ans[i], v = ans[j];
			if(!g[u][v])	return false;
		}
	}
	return true;
}

bool judgeMax(){
	bool h[maxn];
	memset(h, 0, sizeof(h));
	for(int i = 0; i < ans.size(); ++i)
		h[ans[i]] = true;
	for(int u = 1; u <= nv; ++u){
		if(!h[u]){
			bool flag = true;
			for(int j = 0; j < ans.size(); ++j){
				int v = ans[j];
				if(!g[u][v])	flag = false;
			}
			if(flag)	return false;
		}
	}
	return true;
}

int main(){
	scanf("%d%d", &nv, &ne);
	for(int i = 0; i < ne; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		int num;
		scanf("%d", &num);
		ans.resize(num);
		for(int j = 0; j < num; ++j)
			scanf("%d", &ans[j]);
		bool isMax = judgeMax();
		bool isCli = judgeCli();
		if(!isCli)	printf("Not a Clique\n");
		else if(!isMax)	printf("Not Maximal\n");
		else printf("Yes\n");
	}
	return 0;
}
