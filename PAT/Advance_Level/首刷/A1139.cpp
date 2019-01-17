#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define male true
#define female false;
const int maxn = 1e4;
struct node{
	bool gender;
	vector<int> f;
}peo[maxn];
struct Ans{
	int a, b;
};
int n, m;
vector<int> g[maxn];

bool cmp(Ans f1, Ans f2){
	if(f1.a != f2.a)
		return f1.a <= f2.a;
	return f1.b < f2.b;
}

int change(char s[]){
	int i = 0, ans = 0;
	if(s[0] == '-'){
		i = 1;
	}
	for(;i < strlen(s); ++i){
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		char a[6], b[6];
		scanf("%s%s", a, b);	//防止出现+0000和-0000的情况
		int na = change(a);
		int nb = change(b);
		if(a[0] != '-')	peo[na].gender = male;
		else	peo[na].gender = female;
		if(b[0] != '-')	peo[nb].gender = male;
		else	peo[nb].gender = female;
		g[na].push_back(nb);
		g[nb].push_back(na);
		if(peo[na].gender == peo[nb].gender){
			peo[na].f.push_back(nb);
			peo[nb].f.push_back(na);
		}
	}
	int k;
	scanf("%d", &k);
	for(int index = 0; index < k; ++index){
		int a, b;
		vector<Ans> ans;
		scanf("%d%d", &a, &b);
		a = abs(a); b = abs(b);
		for(int i = 0; i < peo[a].f.size(); ++i){
			int f1 = peo[a].f[i];
			if(f1 ==  b)	continue;			//防止出现A->B->A->B
			for(int j = 0; j < peo[b].f.size(); ++j){
				int f2 = peo[b].f[j];
				if(f2 == a)	continue;
				int tot;
				for(tot = 0; tot < g[f1].size(); ++tot){	//用邻接矩阵超时
					if(g[f1][tot] == f2)
						break;
				}
				if(tot != g[f1].size()){
					Ans temp;
					temp.a = f1;
					temp.b = f2;
					ans.push_back(temp);
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); ++i){
			printf("%04d %04d\n", ans[i].a, ans[i].b);
		}
	}
	return 0;
}
