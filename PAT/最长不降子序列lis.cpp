#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 100;
int dp[maxn];
int a[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for(int j = 0; j < i; ++j)
			if ((a[i] >= a[j]) && (dp[j] + 1 > dp[i]))
				dp[i] = dp[j] + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	system("pause");
	return 0;
}