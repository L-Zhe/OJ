#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
struct node{
	int flag, score;
	ll id;
	int local_rank, rank;
	node(ll _id, int f, int s): id(_id), flag(f), score(s){}
};
vector<node> a;

bool cmp(node a,  node b){
	if(a.score != b.score)
		return a.score > b.score;
	else 
		return a.id < b.id;
}

int main(){
	int n, k;
	scanf("%d", &n);
	int index = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &k);
		for(int j = 0; j < k; ++j){
			int score;
			ll id;
			scanf("%lld%d", &id, &score);
			a.push_back(node{id, i, score});
		}
		sort(a.begin() + index, a.end(), cmp);
		int rank = 1;
		a[index++].local_rank = 1;
		while(index < a.size()){
			++rank;
			if(a[index].score == a[index - 1].score)
				a[index].local_rank = a[index - 1].local_rank;
			else
				a[index].local_rank = rank;
			++index;
		}
	}
	sort(a.begin(), a.end(), cmp);
	for(int i = 0; i < a.size(); ++i){
		if(i == 0)	a[i].rank = 1;
		else if(a[i].score == a[i - 1].score)
			a[i].rank = a[i - 1].rank;
		else
			a[i].rank = i + 1;
	}
	printf("%d\n", a.size());
	for(int i = 0; i < a.size(); ++i){
		printf("%013lld %d %d %d\n", a[i].id, a[i].rank, a[i].flag, a[i].local_rank);
	}
	return 0;
}

