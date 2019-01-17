#include<iostream>
using namespace std;

const int maxn = 1e4 + 10;
struct node{
	int u, v;
}e[maxn];
bool Hash[maxn];
int n, m, k;

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &e[i].u, &e[i].v);
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		fill(Hash, Hash + n, false);
		int num;
		bool flag = true;
		scanf("%d", &num);
		for(int j = 0; j < num; ++j){
			int u;
			scanf("%d", &u);
			Hash[u] = true;
		}
		for(int i = 0; i < m; ++i){
			int u = e[i].u, v = e[i].v;
			if(!Hash[u] && !Hash[v])
				flag = false;
		}
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
}
