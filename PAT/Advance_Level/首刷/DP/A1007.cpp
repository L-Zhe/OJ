#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10;
int a[maxn], dp[maxn], s[maxn];
int k;

int main(){
	bool flag = false;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d", a + i);
		if(a[i] >= 0)
			flag = true;
	}
	if(!flag){
		printf("0 %d %d\n", a[0], a[k - 1]);
		return 0;
	}
	int u = 0;
	dp[0] = a[0];
	s[0] = 0;
	for(int i = 1; i < k; ++i){
		if(dp[i - 1] + a[i] > a[i]){
			dp[i] = dp[i - 1] + a[i];
			s[i] = s[i - 1];
		}else{
			dp[i] = a[i];
			s[i] = i;
		}
		if(dp[u] < dp[i])
			u = i;
	}
	printf("%d %d %d\n", dp[u], a[s[u]], a[u]);
	return 0;
}
