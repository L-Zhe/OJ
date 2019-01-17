/*===================================================================================
A1111 Online Map（30 分）
=====================================================================================
Input our current position and a destination, an online map can recommend several
paths. Now your job is to recommend two paths to your user: one is the shortest,
and the other is the fastest. It is guaranteed that a path exists for any request.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives two
positive integers N (2≤N≤500), and M, being the total number of streets intersections
on a map, and the number of streets, respectively. Then M lines follow, each describes
a street in the format:
V1 V2 one-way length time
where V1 and V2 are the indices (from 0 to N−1) of the two ends of the street;
one-way is 1 if the street is one-way from V1 to V2, or 0 if not; length is the
length of the street; and time is the time taken to pass the street.
Finally a pair of source and destination is given.
-------------------------------------------------------------------------------------
Output Specification:
For each case, first print the shortest path from the source to the destination
with distance D in the format:
Distance = D: source -> v1 -> ... -> destination
Then in the next line print the fastest path with total time T:
Time = T: source -> w1 -> ... -> destination
In case the shortest path is not unique, output the fastest one among the shortest
paths, which is guaranteed to be unique. In case the fastest path is not unique,
output the one that passes through the fewest intersections, which is guaranteed
to be unique.
In case the shortest and the fastest paths are identical, print them in one line
in the format:
Distance = D; Time = T: source -> u1 -> ... -> destination
-------------------------------------------------------------------------------------
Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5

Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
------------------
Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5

Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5
===================================================================================*/


#include<iostream>
#include<vector>
using namespace std;

const int maxn = 510;
const int inf = 0x3fffffff;
int dis[maxn][maxn], tim[maxn][maxn], d[maxn], t[maxn];
int n, m;
bool vis[maxn];
int preD[maxn], preT[maxn];
vector<int> pre1, pre2;

void DijkstraD(int st){
    int te[maxn];
    fill(te, te + maxn, inf);
    fill(d, d + maxn, inf);
    fill(vis, vis + maxn, false);
    d[st] = 0;
    te[st] = 0;
    for(int i = 0; i < n; ++i){
        int u= -1, MIN = inf;
        for(int j = 0; j < n; ++j){
            if(vis[j] == false && d[j] < MIN)
                MIN = d[u = j];
        }
        if(u == -1)  return;
        vis[u] = true;
        for(int v = 0; v < n; ++v){
            if(vis[v] == false && dis[u][v] != inf){
                if(d[v] > d[u] + dis[u][v]){
                    d[v] = d[u] + dis[u][v];
                    te[v] = te[u] + tim[u][v];
                    preD[v] = u;
                }else if(d[v] == d[u] + dis[u][v]){
                    if(te[v] > te[u] + tim[u][v]){
                        te[v] = te[u] + tim[u][v];
                        preD[v] = u;
                    }
                }
            }
        }
    }
}

void DijkstraT(int st){
    int num[maxn];
    fill(num, num + maxn, inf);
    fill(t, t + maxn, inf);
    fill(vis, vis + maxn, false);
    t[st] = 0;
    num[st] = 0;
    for(int i = 0; i < n; ++i){
        int u = -1, MIN = inf;
        for(int j = 0; j < n; ++j){
            if(vis[j] == false && t[j] < MIN){
                MIN = d[u = j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; ++v){
            if(vis[v] == false && tim[u][v] != inf){
                if(t[v] > t[u] + tim[u][v]){
                    t[v] = t[u] + tim[u][v];
                    preT[v] = u;
                    num[v] = num[u] + 1;
                }else if(t[v] == t[u] + tim[u][v]){
                    if(num[v] > num[u] + 1){
                        num[v] = num[u] + 1;
                        preT[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int index, vector<int> &pre, int pre1[]){
    while(index != -1){
        pre.push_back(index);
        index = pre1[index];
    }
}

void print(vector<int> a){
    for(int i = a.size() - 1; i >= 0; --i){
        printf("%d", a[i]);
        if(i != 0)
            printf(" -> ");
    }
    printf("\n");
}

int main(){
    freopen("data.txt", "r", stdin);
    fill(dis[0], dis[0] + maxn * maxn, inf);
    fill(tim[0], tim[0] + maxn * maxn, inf);
    fill(preD, preD + maxn, -1);
    fill(preT, preT + maxn, -1);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        int u, v, flag = 0, dd, tt;
        scanf("%d%d%d%d%d", &u, &v, &flag, &dd, &tt);
        if(flag == 0){
            dis[u][v] = dis[v][u] = dd;
            tim[u][v] = tim[v][u] = tt;
        }
        else{
            dis[u][v] = dd;
            tim[u][v] = tt;
        }
    }
    int st ,ed;
    scanf("%d%d", &st, &ed);
    DijkstraD(st);
    DijkstraT(st);
    DFS(ed, pre1, preD);
    DFS(ed, pre2, preT);
    bool flag = true;
    int index = ed;
    while(preD[index] != -1 && preT[index] != -1){
        if(preD[index] != preT[index]){
            flag = false;
            break;
        }
        index = preD[index];
    }
    if(flag){
        printf("Distance = %d; Time = %d: ", d[ed], t[ed]);
        print(pre1);
    }
    else{
        printf("Distance = %d: ", d[ed]);
        print(pre1);
        printf("Time = %d: ", t[ed]);
        print(pre2);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}