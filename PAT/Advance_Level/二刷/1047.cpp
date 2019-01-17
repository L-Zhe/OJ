#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 2510;
struct node{
	char s[5];
	node(char _s[]){
		strcpy(s, _s);
	}
};
vector<node> course[maxn];
int n, k;

bool cmp(node a, node b){
	return strcmp(a.s, b.s) < 0;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		char s[5];
		int c;
		scanf("%s%d", s, &c);
		node temp(s);
		int numC;
		for(int j = 0; j < c; ++j){
			scanf("%d", &numC);
			course[numC].push_back(temp);
		}
	}
	for(int i = 1; i <= k; ++i){
		sort(course[i].begin(), course[i].end(), cmp);
		printf("%d %d\n", i, course[i].size());
		for(int j = 0; j < course[i].size(); ++j){
			printf("%s\n", course[i][j].s);
		}
	}
	return 0;
}

