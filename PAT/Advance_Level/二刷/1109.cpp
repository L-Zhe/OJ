#include<iostream>
#include<deque>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10;
struct node{
	char name[10];
	int height;
}a[maxn];
int n, k;

bool cmp(node a, node b){
	if(a.height != b.height)
		return a.height > b.height;
	else
		return strcmp(a.name, b.name) < 0;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%s %d", a[i].name, &a[i].height);
	}
	sort(a, a + n, cmp);
	int num = n / k + n % k;
	deque<node> ans;
	int i = 0;
	bool flag = true;
	while(i < n){
		for(int j = 0; j < num; ++j){
			if(j % 2 == 0)	ans.push_back(a[i + j]);
			else	ans.push_front(a[i + j]);
		}
		for(int j = 0; j < ans.size(); ++j){
			if(j != 0)	printf(" ");
			printf("%s", ans[j].name);
		}
		printf("\n");
		i += num;
		num = n / k;
		ans.clear();
	}  
	return 0;
}
