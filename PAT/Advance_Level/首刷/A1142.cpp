#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 210;
int g[maxn][maxn];
bool h[maxn];
int nv, ne, m, k;

void judge(vector<int> a){
	bool isC = true, isMc = true;
	for(int i = 0; i < a.size(); ++i){
		for(int j = i + 1; j < a.size(); ++j){
			int u = a[i], v = a[j];
			if(g[u][v] == 0){
				isC = false;
				break;
			}
		}
		if(!isC)	break;
	}
	if(isC){
		for(int u = 1; u <= nv; ++u){
			if(!h[u]){
				int cnt = 0;
				for(int j = 0; j < a.size(); ++j){
					int v = a[j];
					if(g[u][v] == 1){
						++cnt;
					}
				}
				if(cnt == a.size()){
					isMc = false;
					break;
				}
			}
		}
	}
	if(isC && isMc)	printf("Yes\n");
	else if(isC)	printf("Not Maximal\n");
	else printf("Not a Clique\n");
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &nv, &ne);
	for(int i = 0; i < ne; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		scanf("%d", &k);
		memset(h, 0, sizeof(h));
		vector<int>	a;
		for(int j = 0; j < k; ++j){
			int temp;
			scanf("%d", &temp);
			a.push_back(temp);
			h[temp] = true;
		}
		judge(a);
	}
	return 0;
}
