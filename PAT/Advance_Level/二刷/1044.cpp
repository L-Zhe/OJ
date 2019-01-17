#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> chain;
struct node{
	int i, j;
	int M;
	node(int _i, int _j){
		i = _i; 
		j = _j;
		M = chain[j] - chain[i - 1];
	}
};
vector<node> ans;
int n, m;

bool cmp(node a, node b){
	if(a.M != b.M)
		return a.M < b.M;
	else
		return a.i < b.i;		
}

int main(){
	scanf("%d%d", &n, &m);
	chain.resize(n + 1);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &chain[i]);
		chain[i] += chain[i - 1];
	}
	for(int i = 1; i <= n; ++i){
		int j = lower_bound(chain.begin() + i, chain.end(), m + chain[i - 1]) - chain.begin();
		if(j < chain.size())
			ans.push_back(node{i, j});
	}
	sort(ans.begin(), ans.end(), cmp);
	int M = ans[0].M;
	for(int i = 0; i < ans.size(); ++i){
		if(ans[i].M != M)	break;
		printf("%d-%d\n", ans[i].i, ans[i].j);
	}
	return 0;
} 
