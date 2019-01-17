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
using namespace std;

const int maxv = 510;
const int INF = 0X3FFFFFFF;
typedef struct {
	int v, dis, cost;
}Node;

vector<Node> Adj[maxv];
vector<int> pre[maxv];
vector<int> temp_path, path;
bool vis[maxv];
int d[maxv];
int N, M, S, D;
int optvalue;

void Dijstra(int s) {
	fill(d, d + maxv, INF);
	fill(vis, vis + maxv, false);
	d[s] = 0;
	for (int i = 0; i < N; ++i) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; ++j)
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		if (u == -1) return;
		vis[u] = true;
		for (int j = 0; j < Adj[u].size(); ++j) {
			int v = Adj[u][j].v;
			int _dis = Adj[u][j].dis;
			if (vis[v] == false) {
				if (d[u] + _dis < d[v]) {
					d[v] = d[u] + _dis;
					pre[v].clear();
					pre[v].push_back(u);
				}
				if (d[u] + _dis == d[v])
					pre[v].push_back(u);
			}
		}
	}
}

void DFS(int v) {
	if (v == S) {
		temp_path.push_back(v);
		int value = 0;
		for (int i = temp_path.size() - 1; i > 0; --i) {
			int id = temp_path[i], idNext = temp_path[i - 1];
			for(int j = 0; j < Adj[id].size(); ++j)
				if(Adj[id][j].v == idNext)
					value += Adj[id][j].cost;
		}
		if (value < optvalue) {
			optvalue = value;
			path = temp_path;
		}
		temp_path.pop_back();
		return;
	}
	temp_path.push_back(v);
	for (int i = 0; i < pre[v].size(); ++i)
		DFS(pre[v][i]);
	temp_path.pop_back();
}

int main() {
	while (scanf("%d%d%d%d", &N, &M, &S, &D) == 4) {
		for (int i = 0; i < maxv; ++i) {
			pre[i].clear();
			Adj[i].clear();
		}
		path.clear();
		temp_path.clear();


		for (int i = 0; i < M; ++i) {
			int c1, c2;
			Node c;
			cin >> c1 >> c2 >> c.dis >> c.cost;
			c.v = c1;
			Adj[c2].push_back(c);
			c.v = c2;
			Adj[c1].push_back(c);
		}
		Dijstra(S);
		optvalue = INF;
		DFS(D);
		for (int i = path.size() - 1; i >= 0; --i)
			cout << path[i] << " ";
		cout << d[D] << " " << optvalue;

	}
	return 0;
}
