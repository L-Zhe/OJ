#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 1e5;
const int maxv = 1e3;
int N;
int ans[maxv][maxv];
int a[maxn];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", a + i);
	sort(a, a + N, cmp);
	int n = sqrt(N);
	while(N % n != 0)	--n;
	int m = N / n;
	int tot = 1, i = 0, j = 0;
	ans[0][0] = a[0];
	while(tot < N){
		while(j + 1 < n && !ans[i][j + 1])	ans[i][++j] = a[tot++];
		while(i + 1 < m && !ans[i + 1][j])	ans[++i][j] = a[tot++];
		while(j - 1 >= 0 && !ans[i][j - 1])	ans[i][--j] = a[tot++];
		while(i - 1 >= 0 && !ans[i - 1][j])	ans[--i][j] = a[tot++];
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(j != 0)	printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
