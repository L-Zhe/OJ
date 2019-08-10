#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 1e3 + 10;
char s[maxn];
int dp[maxn][maxn];

int main(){
	fgets(s, maxn, stdin);
	int ans = 1, len = strlen(s);
	fill(dp[0], dp[0] + maxn * maxn, 0);
	for(int i = 0; i < len; ++i){
		dp[i][i] = 1;
		if(i < len - 1){
			if(s[i] == s[i + 1]){
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	for(int L = 3; L <= len; ++L){
		for(int i = 0; i + L - 1 < len; ++i){
			int j = i + L - 1;
			if(s[j] == s[i] && dp[i + 1][j - 1] == 1){
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
