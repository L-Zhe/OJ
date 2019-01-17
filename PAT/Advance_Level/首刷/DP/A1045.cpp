#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 210;
const int maxL = 1e4 + 10;
int n, m, l;
int dp[maxL], a[maxL], hash[maxn];

int main(){
	scanf("%d%d", &n, &m);
	fill(hash, hash + maxn, -1);
	for(int i = 0; i < m; ++i){
		int color;
		scanf("%d", &color);
		hash[color] = i;
	}
	scanf("%d", &l);
	int len = 0;
	for(int i = 0; i < l; ++i){
		int temp;
		scanf("%d", &temp);
		if(hash[temp] >= 0){
			a[len++] = hash[temp];
		}
	}
	int ans = -1;
	for(int i = 0; i < len; ++i){
		dp[i] = 1;
		for(int j = 0; j < i; ++j){
			if(a[i] >= a[j]){
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
