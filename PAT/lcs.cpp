#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
string s1, s2;
int main() {
	cin >> s1 >> s2;
	const int len1 = s1.length() + 1;
	const int len2 = s2.length() + 1;
	int **dp = new int*[len1];
	for (int i = 0; i < len1; ++i)
		dp[i] = new int[len2];
	for (int i = 0; i < len1; ++i)
		dp[i][0] = 0;
	for (int i = 0; i < len2; ++i)
		dp[0][i] = 0;
	for (int i = 1; i < len1; ++i) {
		for (int j = 1; j < len2; ++j) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[len1 - 1][len2 - 1] << endl;
	system("pause");
	return 0;
}
