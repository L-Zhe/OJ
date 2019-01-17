#include<stdio.h>
#define bool int
#define true 1
#define false 0
#define maxn 10000

int coin[maxn], temp[maxn], h[maxn];
int n, m;
bool flag = false;

void search(int index, int tot, int total){
	if(total > m || flag)	return;
	if(index >= n || total == m){
		if(total != m)	return;
		for(int i = 0; i < tot; ++i){
			if(i != 0)	printf(" ");
			printf("%d", temp[i]);
		}
		flag = true;
		return;
	}
	temp[tot] = coin[index];
	search(index + 1, tot + 1, total + coin[index]);
	search(index + 1, tot, total);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		++h[temp];
	}
	int index = 0;
	for(int i = 0; i < maxn; ++i){
		while(h[i] != 0){
			coin[index++] = i;
			--h[i];
		}
	}
	search(0, 0, 0);
	if(!flag)	printf("No Solution\n");
	return 0;
}
