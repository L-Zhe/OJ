#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
unordered_map<int, int> mp;
vector<int> ans, temp;
bool h[maxn];
int n, k;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		mp[u] = v;
		mp[v] = u;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		int temp;
		scanf("%d", &temp);
		ans.push_back(temp);
		h[temp] = true;
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < k; ++i){
		int u = ans[i];
		if(mp.find(u) == mp.end() || !h[mp[u]]){
			temp.push_back(u);
		}
	}
	printf("%d\n", temp.size());
	for(int i = 0; i < temp.size(); ++i){
		if(i != 0)	printf(" ");
		printf("%05d", temp[i]);
	}
	return 0;
}
