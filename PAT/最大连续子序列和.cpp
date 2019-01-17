#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 100;
int a[maxn], dp[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dp[0] = a[0];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		dp[i] = max(a[i], dp[i - 1] + a[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	system("pause");
	return 0;
}