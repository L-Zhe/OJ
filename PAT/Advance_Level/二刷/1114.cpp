#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10;
int father[maxn], cnt[maxn];
double area[maxn], numa[maxn];
bool h[maxn];
int n;
vector<int> ans;

void init(){
	for(int i = 0; i < maxn; ++i)
		father[i] = i;
}

int findFather(int a){
	int x = a;
	while(x != father[x])	x = father[x];
	while(a != father[x]){
		int temp = father[a];
		father[a] = x;
		a = temp;
	}
	return x;
}

void Union(int a, int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa < fb)	father[fb] = fa;
	else	father[fa] = fb;
}

bool cmp(int a, int b){
	double avga = area[a] / cnt[a];
	double avgb  = area[b] / cnt[b];
	if(avga != avgb)	return avga > avgb;
	else return a < b;
}

int main(){
	init();
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int id, fa, ma, k;
		scanf("%d%d%d%d", &id, &fa, &ma, &k);
		h[id] = true;
		if(fa != -1){
			Union(id, fa);
			h[fa] = true;
		}
		if(ma != -1){
			Union(id, ma);
			h[ma] = true;
		}	
		for(int j = 0; j < k; ++j){
			int child;
			scanf("%d", &child);
			if(child != -1){
				Union(id, child);
				h[child] = true;
			}	
		}
		scanf("%lf%lf", &numa[id], &area[id]);
	}
	for(int i = 0; i < maxn; ++i){
		if(h[i]){
			if(father[i] == i)	ans.push_back(i);
			int root = findFather(i);
			++cnt[root];
			if(root != i){
				area[root] += area[i];
				numa[root] += numa[i];
			}	
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); ++i){
		printf("%04d %d %.3f %.3f\n", ans[i], cnt[ans[i]], numa[ans[i]] / cnt[ans[i]], area[ans[i]] / cnt[ans[i]]);
	}
	return 0;
}
