#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1000;
int hash[maxn];
vector<int> ans;
int n;

void gen(int index){
	if(index == n + 1){
		for(int i = 0; i < ans.size(); ++i)
			printf("%d ", ans[i]);
		printf("\n");
	}
	for(int i = 1; i <= n; ++i){
		if(hash[i] == false){
			hash[i] = true;
			ans.push_back(i);
			gen(index + 1);
			hash[i] = false;
			ans.pop_back();
		}
	}
}

int main(){
	n = 3;
	hash[0] = true;
	gen(1);
	return 0;
}