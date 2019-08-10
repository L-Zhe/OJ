#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n, m, l;
vector<int> a, v;	//a输入, v每个人的状态(1是平民，-1是狼人)
vector<int> ans;
bool flag = false;

void dfs(int st, int index){
	if(flag)	return;
	if(index == 0){
		vector<int> lie;
		for(int i = 1; i <= n; ++i){
			if(a[i] * v[abs(a[i])] < 0)
				lie.push_back(i);
		}
		int cnt = 0;
		for(int i = 0; i < lie.size(); ++i)
			if(v[lie[i]] < 0)	++cnt;
		if(lie.size() == l && cnt >= 1 && cnt < m){
			flag = true;
			for(int i = n; i >= 1; --i){
				if(v[i] < 0)	ans.push_back(i);
			}
		}				
		return;
	}
	for(int i = st ; i >= 1; --i){
		v[i] = -1;
		dfs(i - 1, index - 1);
		v[i] = 1;
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &l);
	v.resize(n + 1);
	a.resize(n + 1);
	fill(v.begin(), v.end(), 1);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dfs(n, m);
	if(!flag){
		printf("No Solution");
		return 0;
	}
	for(int i = 0; i < ans.size(); ++i){
		if(i != 0)	printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
