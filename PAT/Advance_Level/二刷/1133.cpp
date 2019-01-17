#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5  +10;
struct node{
	int address, next;
	int data, rank, index;
	bool flag;
	node(){
		flag = false;
		rank = index = 0;
	}
}a[maxn];
int n, k, st;

bool cmp(node a, node b){
	if(a.flag != b.flag)	return a.flag > b.flag;
	else if(a.rank != b.rank)	return a.rank < b.rank;	
	else return a.index < b.index;
}

int main(){
	scanf("%d%d%d", &st, &n, &k);
	for(int i = 0; i < n; ++i){
		int address, data, next;
		scanf("%d%d%d", &address, &data, &next);
		a[address].address = address;
		a[address].data = data;
		a[address].next = next;
		if(data < 0)	a[address].rank = 1;
		else if(data >= 0 && data <= k)	a[address].rank = 2;
		else	a[address].rank = 3;
	}
	int cnt = 0, index = 0;
	while(st != -1){
		a[st].flag = true;
		a[st].index = ++index;
		++cnt;
		st = a[st].next;
	}
	sort(a, a + maxn, cmp);
	for(int i = 0; i < cnt; ++i){
		if(i != 0)	printf("%05d\n", a[i].address);
		printf("%05d %d ", a[i].address, a[i].data);
	}
	printf("-1");
	return 0;
}
