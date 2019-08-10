#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 40010;
const int maxc = 2510;
struct node{
	char name[5];
	vector<int> a;
}stu[maxn];
vector<int> course[maxc];
int n, m;

bool cmp(node a, node b){
	return strcmp(a.name, b.name) < 0;
}

int main(){
	freopen("data.txt", "r", stdin);
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		int k, temp;
		scanf("%s%d", stu[i].name, &k);
		for(int j = 0; j < k; ++j){
			scanf("%d", &temp);
			stu[i].a.push_back(temp);
		}
	}
	sort(stu, stu + n, cmp);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < stu[i].a.size(); ++j){
			course[stu[i].a[j]].push_back(i);
		}
	}
	for(int i = 1; i <= m; ++i){
		printf("%d %d\n", i, course[i].size());
		for(int j = 0; j < course[i].size(); ++j)
			printf("%s\n", stu[course[i][j]].name);
	}
	return 0;
}