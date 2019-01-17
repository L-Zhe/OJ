#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10;
string s[maxn];
int n;

bool cmp(string a, string b){
	return a + b < b + a;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	sort(s, s + n, cmp);
	string ans;
	for(int i = 0; i < n; ++i)
		ans += s[i];
	while(ans.length() > 1 && ans[0] == '0')
		ans.erase(ans.begin());
	cout << ans;
	return 0;
}
