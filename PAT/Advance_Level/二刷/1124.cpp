#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<string, bool> mp;
int n, st, step;
string name;

int main(){
	ios::sync_with_stdio(false);
// 	freopen("data.txt", "r", stdin);
	cin >> n >> step >> st;
	int cnt = 0;
	bool flag = false;
	for(int i = 1; i <= n; ++i){
		cin >> name;
		if(mp[name])	continue;
		if(i >= st && cnt % step == 0){
			mp[name] = true;
			cout << name << endl;
			flag = true;
		}
		if(flag)	++cnt;
	}
	if(!flag)	printf("Keep going...");
	return 0;
}
