#include<iostream>
#include<vector>
using namespace std;

int n, r;
vector<int> ans;

bool judge(){
	do{
		ans.push_back(n % r);
		n /= r;
	}while(n > 0);
	for(int i = 0; i < ans.size() / 2; ++i){
		if(ans[i] != ans[ans.size() - 1 - i])
			return false;
	}
	return true;
}

int main(){
	scanf("%d%d", &n, &r);
	if(judge())
		printf("Yes\n");
	else
		printf("No\n");
	for(int i = ans.size() - 1; i >= 0; --i){
		printf("%d", ans[i]);
		if(i != 0)	printf(" ");
	}
	return 0;
}
