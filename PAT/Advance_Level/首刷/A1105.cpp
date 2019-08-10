#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 100;
vector<int> a;
int N;
int ans[maxn][maxn];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	scanf("%d", &N);
	fill(ans[0], ans[0] + maxn * maxn, 0);
	for(int i = 0; i < N; ++i){
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}
	sort(a.begin(), a.end(), cmp);
	int m, n;
	n = sqrt(N);z
	while(n > 1 & N % n != 0){
		n -= 1;
	}
	m = N / n;
	int x = 0, y = 0, tot = 1;
	ans[0][0] = a[0];
	while(tot < N){
		while(y + 1 < n && !ans[x][y + 1])	ans[x][++y] = a[tot++];
		while(x + 1 < m && !ans[x + 1][y])	ans[++x][y] = a[tot++];
		while(y - 1>= 0 && !ans[x][y - 1])	ans[x][--y] = a[tot++];
		while(x - 1 >= 0 && !ans[x - 1][y])	ans[--x][y] = a[tot++];
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(j != 0)
				printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
