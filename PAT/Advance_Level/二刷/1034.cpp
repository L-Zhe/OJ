#include<iostream>
#include<unordered_map>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 2020;
int g[maxn][maxn], total[maxn];
int n, k, numPerson = 1;
unordered_map<int, string> int2str;
unordered_map<string, int> str2int;
bool inq[maxn];

struct node{
	int totalm, peo;
	string index;
	node(string i, int m, int p): index(i), totalm(m), peo(p){}
};

int change(string s){
	if(str2int.find(s) == str2int.end()){
		str2int[s] = numPerson;
		int2str[numPerson] = s;
		return numPerson++; 
	}else{
		return str2int[s];
	}
}

node bfs(int st){
	int index = 0, totalmin = 0, peo = 0;
	queue<int> q;
	q.push(st);
	inq[st] = true;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		++peo;
		if(total[index] < total[top]){
			index = top;
		}
		for(int v = 1; v < numPerson; ++v){
			if(g[top][v] != 0 && !inq[v]){
				q.push(v);
				inq[v] = true;
			}
			totalmin += g[top][v];	
			g[top][v] = 0;
		}
	}
	node ans(int2str[index], totalmin, peo);
	return ans;
}

vector<node> ans;
int BFS(){
	for(int i = 1; i < numPerson; ++i){
		if(!inq[i]){
			node temp = bfs(i);
			if(temp.totalm > k && temp.peo > 2){
				ans.push_back(temp);
			}
		}
	}
}

bool cmp(node a, node b){
	return a.index < b.index;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		string s1, s2;
		int m;
		cin >> s1 >> s2 >> m;
		int u = change(s1);
		int v = change(s2);
		g[u][v] = m;
		total[u] += m;
		total[v] += m;
	}
  BFS();
	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i].index << " " << ans[i].peo << endl;
	}
	return 0;
}
