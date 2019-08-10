#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int maxn = 10000;
string s;
int dp[maxn][maxn];
int ans = 1;
int main() {
	cin >> s;
	int len = s.size();
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len; ++i) {
		dp[i][i] = 0;
		if ((i < len - 1) && (s[i] == s[i + 1])) {
			dp[i][i + 1] = 1;
			ans = 2;
		}
	}
	for (int l = 3; l < len; ++l) {
		for (int i = 0; i < len - l; ++i) {
			int j = i + l - 1;
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1] + 1;
				ans = l;
			}
		}
	}
	cout << ans;
	system("pause");
	return 0;
}