#include<iostream>
#include<vector>
using namespace std;

const int maxn = 210;
const int inf = 0x3fffffff;

int g[maxn][maxn];
int m, n, k;

bool isC(vector<int> a){
	int num = a.size();
	if(a[0] != a[num - 1])	return false;
	for(int i = 1; i < num; ++i)
		if(g[a[i - 1]][a[i]] == 0)	return false;
	vector<bool> h(n + 1);
	int cnt = 0;
	for(int i = 0; i < a.size(); ++i){
		if(!h[a[i]]){
			++cnt;
			h[a[i]] = true;
		}
	}
	if(cnt != n)	return false;
	return true;
}
bool TS(vector<int> a){
	if(a.size() != n + 1)	return false;
	vector<bool> h(n + 1);
	for(int i =1; i < a.size(); ++i){
		if(h[a[i]])	return false;
		h[a[i]]	=	true;
	}

	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		g[u][v] = g[v][u] = dis;
	}
	scanf("%d", &k);
	int u, MIN = inf;
	for(int i = 0; i < k; ++i){
		int num;
		scanf("%d", &num);
		vector<int> ans(num);
		int total = 0;
		for(int j = 0; j < num; ++j){
			scanf("%d", &ans[j]);
			if(j != 0 && g[ans[j - 1]][ans[j]] == 0)	total = -1;
			if(j != 0 && total != -1)	total += g[ans[j - 1]][ans[j]];
		}
		printf("Path %d:", i + 1);
		if(total < 0)	printf(" NA ");
		else	printf(" %d ", total);
		if(!isC(ans))	printf("(Not a TS cycle)\n");
		else{
			if(total < MIN){
				u = i + 1;
				MIN = total;
			}
			if(!TS(ans))	printf("(TS cycle)\n");
			else printf("(TS simple cycle)\n");
		}
	}
	printf("Shortest Dist(%d) = %d", u, MIN);
	return 0;
}
