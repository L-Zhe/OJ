#include<iostream>
#include<vector>
using namespace std;

const int maxn = 210;
int n, m;
int g[maxn][maxn];

int main(){
	scanf("%d%d", &n , &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	int k;
	scanf("%d", &k);
	bool flag;
	vector<bool> h(n + 1);
	for(int i = 0; i < k; ++i){
		flag = true;
		int num;
		scanf("%d", &num);
		if(num != n + 1)	flag = false;
		vector<int> ans(num);
		fill(h.begin(), h.end(), false);
		int cnt = 0;
		for(int j = 0; j < num; ++j){
			scanf("%d", &ans[j]);
			if(!h[ans[j]]){
				++cnt;
				h[ans[j]] = true;
			}
			if(j != 0 && g[ans[j]][ans[j - 1]] == 0)	flag = false;
		}
		if(ans[0] != ans[num - 1])	flag = false;
		if(cnt != n)	flag = false;
		if(flag)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
