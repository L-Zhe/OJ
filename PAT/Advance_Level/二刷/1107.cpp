#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e3 + 10;
int father[maxn], h[maxn]; 
int n;
int c[maxn];
vector<int> ans;

void init(){
	for(int i = 0; i < maxn; ++i){
		father[i] = i;
	}
	fill(h, h + maxn, 0);
	fill(c, c + maxn, 0);
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
	if(fa != fb)
		father[fa] = fb;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	init();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int k, index;
		scanf("%d:", &k);
		for(int j = 0; j < k; ++j){
			scanf("%d", &index);
			if(h[index] == 0)	h[index] = i;
			else{
				Union(h[index], i);	
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(father[i] == i){
				++cnt;
		}
		++c[findFather(i)];
	}
	
	for(int i = n; i >= 1; --i){
		if(c[i] != 0){
			ans.push_back(c[i]);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	bool flag = false;
	for(int i = 0; i < ans.size(); ++i){
		if(flag)	printf(" ");
		flag = true;
		printf("%d", ans[i]);
	}
	return 0;
}
