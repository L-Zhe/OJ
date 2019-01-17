/*===================================================================================
A1030 Travel Plan (30)（30 分）
=====================================================================================
A traveler's map gives the distances between cities along the highways, together
with the cost of each highway. Now you are supposed to write a program to help a
traveler to decide the shortest path between his/her starting city and the destination.
If such a shortest path is not unique, you are supposed to output the one with the
minimum cost, which is guaranteed to be unique.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case starts with a line containing
4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and
hence the cities are numbered from 0 to N-1); M is the number of highways; S and
D are the starting and the destination cities, respectively. Then M lines follow,
each provides the information of a highway, in the format:
City1 City2 Distance Cost
where the numbers are all integers no more than 500, and are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the cities along the shortest path from the
starting point to the destination, followed by the total distance and the total
cost of the path. The numbers must be separated by a space and there must be no
extra space at the end of output.
-------------------------------------------------------------------------------------
Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

Sample Output
0 2 3 3 40
===================================================================================*/

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxv = 510;
const int INF = 0x3fffffff;
class Node{
public:
	int v, dis, cost;
	Node(int _v, int _dis, int _cost):v(_v), dis(_dis), cost(_cost)	{}
};
vector<Node> Adj[maxv];
int d[maxv], c[maxv], num[maxv], pre[maxv];
bool inq[maxv];
int N, M, st, ed;

bool SPFA(int s){
	fill(d, d + maxv, INF);
	fill(c, c + maxv, INF);
	fill(num, num + maxv, 0);
	fill(inq, inq + maxv, false);
	d[s] = 0;
	c[s] = 0;
	queue<int> Q;
	Q.push(s);
	inq[s] = true;
	while(!Q.empty()){
		int n = Q.front();
		Q.pop();
		inq[n] = false;
		for(int i = 0; i < Adj[n].size(); ++i){
			int u = Adj[n][i].v;
			int _cost = Adj[n][i].cost;
			int _dis = Adj[n][i].dis;
			if(d[n] + _dis < d[u]){
				if(inq[u] == false){
					Q.push(u);
					inq[u] = true;
					if(++num[u] > N - 1)
						return false;
				}
				d[u] = d[n] + _dis;
				c[u] = c[n] + _cost;
				pre[u] = n;
			}
			if(d[n] + _dis == d[u]){
				if(c[n] + _cost < c[u]){
					c[u] = c[n] + _cost;
					pre[u] = n;
				}
			}
		}
	}
	return true;
}

void DFS(int s){
	if(s == st){
		cout << s << " ";
		return;
	}
	DFS(pre[s]);
	cout << s << " ";
}

int main(){
	while(scanf("%d%d%d%d", &N, &M, &st, &ed) == 4){
		for(int i = 0; i < maxv; ++i)
			Adj[i].clear();
		for(int i = 0; i < M; ++i){
			int u, v, _dis, _cost;
			cin >> u >> v >> _dis >> _cost;
			Adj[u].push_back(Node(v, _dis, _cost));
			Adj[v].push_back(Node(u, _dis, _cost));
		}
		bool T = SPFA(st);
		if(T == true)
			DFS(ed);
		cout << d[ed] << " " << c[ed];
	}
	return 0;
}
