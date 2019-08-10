#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 210;
int g[maxn][maxn], cnt[maxn];
int n, m, k;

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		bool flag = true;
		int num, now, pre;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &num);
		if(num != n + 1){
			flag = false;
		}
		int fst;
		scanf("%d", &fst);
		++cnt[fst];
		pre = fst;
		for(int j = 1; j < num; ++j){
			scanf("%d", &now);
			if(now > n)
				flag = false;
			if(j != num - 1 && cnt[now] != 0)
				flag = false;
			++cnt[now];
			if(j == num - 1 && now != fst)
				flag = false;
			if(!g[pre][now])
				flag = false;
			pre = now;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
