#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 110;
struct node{
	int id, rank;
	int gi, ge, fg;
	vector<int> cho;
};

struct school{
	int quota;
	int num;
	int last;
	vector<int> peo;
};
vector<node> s;
vector<school> sch;
int m, k;
int n;
bool cmp(node a, node b){
	if(a.fg != b.fg)
		return a.fg > b.fg;
	else
		return a.ge > b.ge;
}

bool cmp2(int a, int b){
	return a < b;
}


int main(){
	//freopen("data.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; ++i){
		school temp;
		scanf("%d", &temp.quota);	
		temp.last = -1;
		temp.num = 0;
		sch.push_back(temp);
	}
	for(int i = 0; i < n; ++i){
		node temp;
		temp.id = i;
		scanf("%d%d", &temp.ge, &temp.gi);
		temp.fg = temp.ge + temp.gi;
		for(int j = 0; j < k; ++j){
			int num;
			scanf("%d", &num);
			temp.cho.push_back(num);
		}
		s.push_back(temp);
	}
	sort(s.begin(), s.end(), cmp);
	s[0].rank = 1;
	for(int i = 1; i < n; ++i){
		if(s[i].fg == s[i - 1].fg && s[i].ge == s[i - 1].ge)
			s[i].rank = s[i-1].rank;
		else 
			s[i].rank = i + 1;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < k; ++j){
			int index = s[i].cho[j];
			int last = sch[index].last;
			int quota = sch[index].quota;
			int num = sch[index].num;
			if(num < quota || (last != -1 && s[i].rank == s[last].rank)){
				sch[index].peo.push_back(s[i].id);
				sch[index].num++;
				sch[index].last = i;
				break;
			}
		}
	}
	for(int i = 0; i < m; ++i){
		sort(sch[i].peo.begin(), sch[i].peo.end(), cmp2);
		for(int j = 0; j < sch[i].peo.size(); ++j){
			if(j != 0)	printf(" ");
			printf("%d", sch[i].peo[j]);
		}
		printf("\n");
	}
	return 0;
}