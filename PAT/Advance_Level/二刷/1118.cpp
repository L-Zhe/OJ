#include<iostream>
using namespace std;

const int maxn = 1e5;
int n;
int father[maxn];
bool h[maxn];

void init(){
	for(int i = 0; i < maxn; ++i)
		father[i] = i; 
}

int findFather(int a){
	int x = a;
	while(x != father[x])	x = father[x];
	while(a != father[a]){
		int temp = father[a];
		father[a] = x;
		a = temp;
	}
	return x;
}

void Union(int a, int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb){
		father[fa] = fb;
	}
}

int main(){
	init();
	int k, index, cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &k);
		int pre;
		for(int j = 0; j < k; ++j){
			scanf("%d", &index);
			if(!h[index]){
				++cnt;
				h[index] = true;
			}
			if(j != 0){
				Union(pre, index);
			}
			pre = index;
		}
	}
	int totalTree = 0;
	for(int i = 1; i < maxn; ++i){
		if(h[i] && father[i] == i){
			++totalTree;
		}
	}
	printf("%d %d\n", totalTree, cnt);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		if(findFather(a) == findFather(b))	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}

