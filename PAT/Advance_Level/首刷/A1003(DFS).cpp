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
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 550;
const int inf = 0x3fffffff;
int G[maxn][maxn], d[maxn], team[maxn];
vector<int> pre[maxn];
bool vis[maxn];
int n, m, st, ed, MAX, num = 0;

void init(){
    fill(G[0], G[0] + maxn*maxn, inf);
    fill(d, d + maxn, inf);
    fill(vis, vis + maxn, false);
}

void Dijkstra(int st){
    d[st] = 0;
    for(int i = 0; i < n; ++i){
        int u = -1, MIN = inf;
        for(int j = 0; j < n; ++j){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; ++v){
            if(vis[v] == false && G[u][v] != inf){
                if(d[v] > d[u] + G[u][v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v] == d[u] + G[u][v])
                    pre[v].push_back(u);
            }
        }
    }
}

void DFS(int index, int total){
    if(index == st){
        if(total > MAX)
        	MAX = total;
        num++;
        return;
    }
    for(int i = 0; i < pre[index].size(); ++i)
        DFS(pre[index][i], total + team[pre[index][i]]);
}

int main(){
    ios::sync_with_stdio(false);
    init();
    cin >> n >> m >> st >> ed;
    for(int i = 0; i < n; ++i)
        cin >> team[i];
    for(int i = 0; i < m; ++i){
        int u, v, len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;
    }
    Dijkstra(st);
    MAX = 0;
    DFS(ed, team[ed]);
    cout << num << " " << MAX;
    return 0;
}