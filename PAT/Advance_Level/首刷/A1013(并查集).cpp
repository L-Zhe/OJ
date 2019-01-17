/*===================================================================================
A1013 Battle Over Cities (25)（25 分）
=====================================================================================
It is vitally important to have all the cities connected by highways in a war. If
a city is occupied by the enemy, all the highways from/toward that city are closed.
We must know immediately if we need to repair any other highways to keep the rest
of the cities connected. Given the map of cities which have all the remaining highways
marked, you are supposed to tell the number of highways need to be repaired, quickly.
For example, if we have 3 cities and 2 highways connecting city~1~-city~2~ and city~1~-city~3~.
Then if city~1~ is occupied by the enemy, we must have 1 highway repaired, that
is the highway city~2~-city~3~.
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. Each case starts with a line containing
3 numbers N (&lt1000), M and K, which are the total number of cities, the number
of remaining highways, and the number of cities to be checked, respectively. Then
M lines follow, each describes a highway by 2 integers, which are the numbers of
the cities the highway connects. The cities are numbered from 1 to N. Finally there
is a line containing K numbers, which represent the cities we concern.
-------------------------------------------------------------------------------------
Output
For each of the K cities, output in a line the number of highways need to be repaired
if that city is lost.
-------------------------------------------------------------------------------------
Sample Input
3 2 3
1 2
1 3
1 2 3

Sample Output
1
0
0
===================================================================================*/

#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1010;
vector<int> G[maxn];
int father[maxn];
bool vis[maxn];
int n, m, k, close;

int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int temp = father[a];
        father[a] = x;
        a = temp;
    }
    return x;
}

void Union(int a, int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb){
        father[fb] = fa;
    }
}

void init(){
    for(int i = 0; i < maxn; ++i){
        father[i] = i;
        vis[i] = false;
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int close;
    for(int i = 0; i < k; ++i){
        cin >> close;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < G[i].size(); ++j){
                int u = i, v = G[i][j];
                if(u == close || v == close)    continue;
                Union(u, v);
            }
        }
        int block = 0;
        for(int i = 1; i <= n; ++i){
            if(i == close)
                continue;
            int f = father[i];
            if(vis[f] == false){
                block++;
                vis[f] = true;
            }
        }
        cout << block << endl;
    }
    return 0;
}
