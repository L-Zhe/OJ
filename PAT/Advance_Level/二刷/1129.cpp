#include<iostream>
#include<set>
using namespace std;
const int maxn = 5e4+ 10;

int cnt[maxn];
struct node{
	int num, cnt;
	node(int _num, int _cnt): num(_num), cnt(_cnt){}
	bool operator <(const node& a)const {
		if(cnt != a.cnt)	return cnt > a.cnt;
		else	return num < a.num;
	}
};
set<node> ans;
int n, t;


int main(){
	scanf("%d%d", &n, &t);
	int temp;
	scanf("%d", &temp);
	ans.insert(node{temp, 1});
	++cnt[temp];
	for(int i =  1; i < n; ++i){
		scanf("%d", &temp);
		printf("%d: ", temp);
		set<node>::iterator it;
		int count = 0;
		for(it = ans.begin(); it != ans.end() && count < t; ++it){
			if(count++ != 0)	printf(" ");
			printf("%d", it->num);
		}
		it = ans.find(node{temp, cnt[temp]});
		if(it != ans.end())	ans.erase(it);
		++cnt[temp];
		ans.insert(node{temp, cnt[temp]});
		printf("\n");
	}
	return 0;
}
