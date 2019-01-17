#include<iostream>
#include<cstring>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10;
struct node{
	char id[21];
	int gp, gmid, gfinal, g;
	node(){
		gp = -1;
		gmid = -1;
		gfinal = -1;
		g = -1;
	}
};
int p, m, n, numPerson = 0;
map<string, int> str2int;
vector<node> ans;

bool cmp(node a, node b){
	if(a.g != b.g)	return a.g > b.g;
	else	return strcmp(a.id, b.id) < 0;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d%d", &p, &m, &n);
	for(int i = 0; i < p; ++i){
		node temp;
		scanf("%s%d", temp.id, &temp.gp);
		if(temp.gp >= 200){
			str2int[temp.id] = ++numPerson;
			ans.push_back(temp);
		}
			
	}
	for(int i = 0; i < m; ++i){
		char id[21];
		int gmid;
		scanf("%s%d", id, &gmid);
		if(str2int[id] != 0){
			int index = str2int[id] - 1;
			ans[index].gmid = gmid;
 		}
	}
	for(int i = 0; i < n; ++i){
		char id[21];
		int gfinal;
		scanf("%s%d", id, &gfinal);
		if(str2int[id] != 0){
			int index = str2int[id] - 1;
			ans[index].gfinal = gfinal;
		}
	}
	for(int i = 0; i < numPerson; ++i){
		if(ans[i].gfinal < ans[i].gmid)	
			ans[i].g = round(0.4  * ans[i].gmid + 0.6 * ans[i].gfinal);
		else
			ans[i].g = ans[i].gfinal;
	}
	sort(ans.begin(), ans.end(), cmp);
	for(int i = 0; i < numPerson; ++i){
		if(ans[i].g < 60)	break;
		printf("%s %d %d %d %d\n", ans[i].id, ans[i].gp, ans[i].gmid, ans[i].gfinal, ans[i].g);
	}
	return 0;
}
