#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 1e3 + 10;
struct node{
	int weight, index, num, rank;
}a[maxn];
int np, ng;
queue<int> q;

bool cmp1(node a, node b){
	return a.index > b.index;
}

bool cmp2(node a, node b){
	return a.num < b.num;
}

int main(){
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; ++i){
		scanf("%d", &a[i].weight);
		a[i].num = i;
	}
	for(int i = 0; i < np; ++i){
		int temp;
		scanf("%d", &temp);
		q.push(temp);
	}
	int cnt, index = 1, total = np; 
	while(q.size() != 1){
		cnt = 0;
		int MAX = 0, Mnum;
		while(cnt < ng && total > 0){
			int top = q.front();
			q.pop();
			a[top].index = index;
			if(a[top].weight > MAX){
				MAX = a[top].weight;
				Mnum = top;
			}
			++cnt;
			--total;
		}
		q.push(Mnum);
		if(total == 0){
			total = q.size();
			++index;
		}
	}
	a[q.front()].index = index;
	sort(a, a + np, cmp1);
	for(int i = 0; i < np; ++i){
		if(i == 0)	a[i].rank = 1;
		else if(a[i].index == a[i - 1].index)
			a[i].rank = a[i - 1].rank;
		else
			a[i].rank = i + 1;
	}
	sort(a, a + np, cmp2);
	for(int i = 0; i < np; ++i){
		if(i != 0)	printf(" ");
		printf("%d", a[i].rank);
	}
	return 0;
}
