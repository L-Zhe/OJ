#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;
int m, n;

int judge(){
	int flag, pre;
	for(int i =2; i <= n; ++i){
		if(ans[i] > ans[i / 2])	flag = 1;
		else if(ans[i] < ans[i / 2])	flag = 2;
		if(i != 2 && flag != pre)	return 0;
		pre = flag;
	}
	return flag;
}

bool space;
void postOrder(int root){
	if(root > n)	return;
	postOrder(root * 2);
	postOrder(root * 2 + 1);
	if(space)	printf(" ");
	space = true;
	printf("%d", ans[root]);
}

int main(){
	scanf("%d%d", &m, &n);
	ans.resize(n + 1);
	for(int i = 0; i < m; ++i){
		for(int j = 1; j <= n; ++j)
			scanf("%d", &ans[j]);
		int flag = judge();
		if(flag == 2)	printf("Max Heap\n");
		else if(flag == 1)	printf("Min Heap\n");
		else	printf("Not Heap\n");
		space = false;
		postOrder(1);
		printf("\n");
	}
}
