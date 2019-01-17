#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	int adress, next, data;
	int rank, pos;
	node(){
		rank = maxn;
	}
}link[maxn];
int st, n, k;

bool cmp1(node a, node b){
	return a.rank < b.rank;
}

bool cmp2(node a, node b){
	return a.pos < b.pos;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d%d", &st, &n, &k);
	for(int i = 0; i < n; ++i){
		int id, data, next;
		scanf("%d%d%d", &id, &data, &next);
		link[id].adress = id;
		link[id].data = data;
		link[id].next = next;
		if(data < 0)	link[id].pos = -1;
		else if(data <= k)	link[id].pos = 0;
		else	link[id].pos = 1;
	}
	int rank = 1, num = 0;
	while(st != -1){
		link[st].rank = rank++;
		st = link[st].next;
		++num;
	}
	sort(link, link + maxn, cmp1);
	stable_sort(link, link + num, cmp2);
	for(int i = 0; i < num ; ++i){
		printf("%05d %d ", link[i].adress, link[i].data);
		if(i != num - 1)
			printf("%05d\n", link[i + 1].adress);
		else
			printf("-1\n");
	}
	return 0;
}
