/*===================================================================================
A1018 Public Bike Management (30)?30 ??
=====================================================================================
There is a public bike service in Hangzhou City which provides great convenience
to the tourists from all over the world. One may rent a bike at any station and
return it to any other stations in the city.
The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity
of all the stations. A station is said to be in perfect condition if it is exactly
half-full. If a station is full or empty, PBMC will collect or send bikes to adjust
the condition of that station to perfect. And more, all the stations on the way
will be adjusted as well.
When a problem station is reported, PBMC will always choose the shortest path to
reach that station. If there are more than one shortest path, the one that requires
the least number of bikes sent from PBMC will be chosen.
\ Figure 1
Figure 1 illustrates an example. The stations are represented by vertices and the
roads correspond to the edges. The number on an edge is the time taken to reach
one end station from another. The number written inside a vertex S is the current
number of bikes stored at S. Given that the maximum capacity of each station is
10. To solve the problem at S~3~, we have 2 different shortest paths:
1. PBMC -> S~1~ -> S~3~. In this case, 4 bikes must be sent from PBMC, because we
can collect 1 bike from S~1~ and then take 5 bikes to S~3~, so that both stations
will be in perfect conditions.
2. PBMC -> S~2~ -> S~3~. This path requires the same time as path 1, but only 3
bikes sent from PBMC and hence is the one that will be chosen.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains 4
numbers: C~max~ (<= 100), always an even number, is the maximum capacity of each
station; N (<= 500), the total number of stations; S~p~, the index of the problem
station (the stations are numbered from 1 to N, and PBMC is represented by the vertex
0); and M, the number of roads. The second line contains N non-negative numbers
C~i~ (i=1,...N) where each C~i~ is the current number of bikes at S~i~ respectively.
Then M lines follow, each contains 3 numbers: S~i~, S~j~, and T~ij~ which describe
the time T~ij~ taken to move betwen stations S~i~ and S~j~. All the numbers in a
line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print your results in one line. First output the number of bikes
that PBMC must send. Then after one space, output the path in the format: 0-&gtS~1~->...-&gtS~p~.
Finally after another space, output the number of bikes that we must take back to
PBMC after the condition of S~p~ is adjusted to perfect.
Note that if such a path is not unique, output the one that requires MINimum number
of bikes that we must take back to PBMC. The judge's data guarantee that such a
path is unique.
-------------------------------------------------------------------------------------
Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

Sample Output:
3 0-&gt2-&gt3 0
===================================================================================*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 510;
const int inf = 0x3fffffff;
int g[maxn][maxn], need[maxn];
int d[maxn];
bool vis[maxn];
vector<int> pre[maxn], temp, ans;
int cmax, n, ed, m;

void Dijkstra(int st){
    fill(d, d + maxn, inf);
    d[st] = 0;
    for (int i = 0; i <= n; ++i){
        int u = -1, MIN = inf;
        for (int j = 0; j <= n; ++j){
            if(vis[j] == false && d[j] < MIN){
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        vis[u] = true;
        for (int v = 0; v <= n; ++v){
            if(g[u][v] != inf){
                if(d[v] > d[u] + g[u][v]){
                    d[v] = d[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v] == d[u] + g[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int out = inf, in = inf;
void DFS(int now){
    if(now == 0){
        int total = 0, carry = 0;
        for (int i = temp.size() - 1; i >= 0; --i){
            int u = temp[i];
            carry -= need[u];
            if(carry < 0){
                total -= carry;
                carry = 0;
            }
        }
        if(total < out){
                out = total;
                ans = temp;
                int = carry;
        }
        else if(total == out && carry < in){
                in = carry;
                ans = temp;
        }
    }
    for (int i = 0; i < pre[now].size(); ++i){
        int v = pre[now][i];
        temp.push_back(v);
        DFS(v);
        temp.pop_back();
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    scanf("%d%d%d%d", &cmax, &n, &ed, &m);
    fill(g[0], g[0] + maxn * maxn, inf);
    need[0] = 0;
    for (int i = 1; i <= n; ++i){
        int temp;
        scanf("%d", &temp);
        need[i] = cmax / 2 - temp;
    }
    for (int i = 0; i < m; ++i){
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        g[u][v] = g[v][u] = dis;
    }
    Dijkstra(0);
    temp.push_back(ed);
    DFS(ed);
    printf("%d ", out);
    for (int i = ans.size() - 1; i >= 0; --i) {
        printf("%d", ans[i]);
        if (i != 0)
            printf("->");
    }
    printf(" %d\n", in);
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}