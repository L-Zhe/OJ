#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 110;
struct node{
	int weight;
	vector<int> child;
}a[maxn];
int n, m, s;
vector<int> ans;

void DFS(int root, int totalW){
	if(totalW > s)	return;
	if(a[root].child.size() == 0){
		if(totalW == s){
			for(int i = 0; i < ans.size(); ++i){
				if(i != 0)	printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		}
		return;
	}
	for(int i = 0; i < a[root].child.size(); ++i){
		int index = a[root].child[i];
		ans.push_back(a[index].weight);
		DFS(index, totalW + a[index].weight);
		ans.pop_back();
	}
}

bool cmp(int i, int j){
	return a[i].weight > a[j].weight;
}

int main(){
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i].weight);
	}
	for(int i = 0; i < m; ++i){
		int id, k, temp;
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; ++j){
			scanf("%d", &temp);
			a[id].child.push_back(temp);
		}
		sort(a[id].child.begin(), a[id].child.end(), cmp);
	}
	ans.push_back(a[0].weight);
	DFS(0, a[0].weight);
	return 0;
}
