#include<iostream>
#include<set>
using namespace std;

const int maxn = 5e4 + 10;
struct node{
	int num, cnt;
	node(int _num, int _cnt):num(_num), cnt(_cnt){}
	bool operator < (const node &a) const{
		return (cnt != a.cnt) ? cnt > a.cnt : num < a.num;
	}
};
int cnt[maxn];
set<node> ans;
int n, k;

int main(){
	int temp;
	scanf("%d%d%d", &n, &k, &temp);
	ans.insert(node(temp, ++cnt[temp]));
	for(int i = 1; i < n; ++i){
		scanf("%d", &temp);
		printf("%d:", temp);
		int j = 0;
		for(set<node>::iterator it = ans.begin(); it != ans.end() && j++ < k; ++it)
			printf(" %d", it->num);
		printf("\n");
		set<node>::iterator it = ans.find(node(temp, cnt[temp]));
		if(it != ans.end())	ans.erase(it);
		++cnt[temp];
		ans.insert(node(temp, cnt[temp]));			
	}
	return 0;
}
