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

int Adj[maxv][maxv], cost[maxv][maxv];
int d[maxv], c[maxv], pre[maxv];
bool vis[maxv];
int N, M, st, ed;


void Dijkstra(int s){
	fill(d, d + maxv, INF);
	fill(c, c + maxv, INF);
	fill(vis, vis + maxv, false);
	fill(pre, pre + maxv, -1);
	d[s] = 0;
	c[s] = 0;
	for(int i = 0; i < N; ++i){
		int u = -1, MIN = INF;
		for(int j = 0; j < N; ++j)
		if(vis[j] == false && d[j] < MIN){
			u = j;
			MIN = d[j];
		}
		if(u == -1)	return;
		vis[u] = true;
		for(int j = 0; j < N; ++j){
			if(vis[j] == false && Adj[u][j] != INF){
				if(d[u] + Adj[u][j] < d[j]){
					d[j] = d[u] + Adj[u][j];
					pre[j] = u;
					c[j] = c[u] + cost[u][j];
				} 
				if(d[u] + Adj[u][j] == d[j]){
					if(c[u] + cost[u][j] < c[j]){
						c[j] = c[u] + cost[u][j];
						pre[j] = u;
					}
				}
			}
		}
	}
}

void DFS(int s){
	if(s == st)
		cout << s << " ";
	else{
		DFS(pre[s]);
		cout << s << " ";
	}
}

int main(){
	while(scanf("%d%d%d%d", &N, &M, &st, &ed) == 4){
		fill(Adj[0], Adj[0] + maxv * maxv, INF);
		fill(cost[0], cost[0] + maxv * maxv, INF);
		for(int i = 0; i < M; ++i){
			int u, v, dis, cos;
			cin >> u >> v >> dis >> cos;
			Adj[u][v] = Adj[v][u] = dis;
			cost[u][v] = cost[v][u] = cos;
		}
		Dijkstra(st);
		DFS(ed);
		cout << d[ed] << " " << c[ed];
	}
	return 0;
}
