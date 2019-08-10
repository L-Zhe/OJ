#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	int address, key, next;
	bool flag;
	node(){
		flag = false;
	}
}a[maxn];
int n, st;

bool cmp(node a, node b){
	if(a.flag != b.flag)
		return a.flag > b.flag;
	else
		return a.key < b.key;
}

int main(){
	scanf("%d%d", &n, &st);
	for(int i = 0; i < n; ++i){
		int _a, _k, _n;
		scanf("%d%d%d", &_a, &_k, &_n);
		a[_a].address = _a;
		a[_a].key = _k;
		a[_a].next = _n;
	}
	int num = 0;
	while(st != -1){
		a[st].flag = true;
		st = a[st].next;
		++num;
	}
	if(num == 0){
		printf("0 -1");
	}else{
		sort(a, a + maxn, cmp);
		printf("%d %05d\n", num, a[0].address);
		for(int i = 0; i < num; ++i){
			printf("%05d %d ", a[i].address, a[i].key);
			if(i != num - 1)	printf("%05d\n", a[i + 1].address);
			else	printf("-1");
		}		
	}
	return 0;
}
