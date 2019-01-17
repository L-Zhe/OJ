#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e6 + 10;
int couple[maxn];
bool here[maxn];
vector<int> seq, ans;
int n, m;

int main(){
	scanf("%d", &n);
	fill(couple, couple + maxn, -1);
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		couple[a] = b;
		couple[b] = a;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		int temp;
		scanf("%d", &temp);
		here[temp] = true;
		seq.push_back(temp);
	}
	for(int i = 0; i < m; ++i){
		int index = seq[i];
		if(couple[index] == -1){
			ans.push_back(index);
		}else{
			int cou = couple[index];
			if(!here[cou])
				ans.push_back(index);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); ++i){
		if(i != 0)	printf(" ");
		printf("%05d", ans[i]);
	}
	return 0;
}
