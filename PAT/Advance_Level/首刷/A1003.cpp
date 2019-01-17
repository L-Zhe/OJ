/*===================================================================================
A1003 Emergency (25)（25 分）
=====================================================================================
As an emergency rescue team leader of a city, you are given a special map of your
country. The map shows several scattered cities connected by some roads. Amount
of rescue teams in each city and the length of each road between any pair of cities
are marked on the map. When there is an emergency call to you from some other city,
your job is to lead your men to the place as quickly as possible, and at the mean
time, call up as many hands on the way as possible.
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. For each test case, the first line contains
4 positive integers: N (<= 500) - the number of cities (and the cities are numbered
from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently
in and that you must save, respectively. The next line contains N integers, where
the i-th integer is the number of rescue teams in the i-th city. Then M lines follow,
each describes a road with three integers c1, c2 and L, which are the pair of cities
connected by a road and the length of that road, respectively. It is guaranteed
that there exists at least one path from C1 to C2.
-------------------------------------------------------------------------------------
Output
For each test case, print in one line two numbers: the number of different shortest
paths between C1 and C2, and the maximum amount of rescue teams you can possibly
gather.\ All the numbers in a line must be separated by exactly one space, and there
is no extra space allowed at the end of a line.
-------------------------------------------------------------------------------------
Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output
2 4
===================================================================================*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int INF = 0x3fffffff;
const int MAXV = 1000;
typedef struct {
	int v, dis;
}Node;
vector<Node> Adj[MAXV];
int d[MAXV], num_d[MAXV], team[MAXV], total_team[MAXV];
bool vis[MAXV];
int N, M, C1, C2;

int max(int m, int n) {
	if (m > n)	return m;
	else	return n;
}

void Dijkstra(int s) {
	fill(vis, vis + MAXV, false);
	fill(d, d + MAXV, INF);
	fill(num_d, num_d + MAXV, 0);
	fill(total_team, total_team + MAXV, 0);
	d[s] = 0;
	total_team[s] = team[s];
	num_d[s] = 1;
	for (int i = 0; i < N; ++i) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; ++j)
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		if (u == -1)	return;
		vis[u] = true;
		for (int j = 0; j < Adj[u].size(); ++j) {
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if (vis[v] == false) {
				if (d[u] + dis < d[v]) {
					d[v] = d[u] + dis;
					num_d[v] = num_d[u];
					total_team[v] = team[v] + total_team[u];
				}
				else if(d[u] + dis == d[v]){ 
					num_d[v] += num_d[u];
					total_team[v] = max(total_team[v], total_team[u] + team[v]);
				} 
			}
		}
	}
}

int main() {
	while (scanf_s("%d%d%d%d", &N, &M, &C1, &C2) == 4) {
		for (int i = 0; i < N; ++i)
			cin >> team[i];
		for (int i = 0; i < M; ++i) {
			int m, n;
			Node c;
			cin >> m >> n >> c.dis;
			c.v = m;
			Adj[n].push_back(c);
			c.v = n;
			Adj[m].push_back(c);
		}
		Dijkstra(C1);
		cout << num_d[C2] << " " << total_team[C2];
	}
	return 0;
}