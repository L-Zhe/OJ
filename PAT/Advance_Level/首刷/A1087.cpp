/*===================================================================================
A1087 All Roads Lead to Rome (30)?30 ??
=====================================================================================
Indeed there are many different tourist routes from our city to Rome. You are supposed
to find your clients the route with the least cost while gaining the most happiness.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains 2
positive integers N (2<=N<=200), the number of cities, and K, the total number of
routes between pairs of cities; followed by the name of the starting city. The next
N-1 lines each gives the name of a city and an integer that represents the happiness
one can gain from that city, except the starting city. Then K lines follow, each
describes a route between two cities in the format "City1 City2 Cost". Here the
name of a city is a string of 3 capital English letters, and the destination is
always ROM which represents Rome.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, we are supposed to find the route with the least cost. If such
a route is not unique, the one with the maximum happiness will be recommended. If
such a route is still not unique, then we output the one with the maximum average
happiness -- it is guaranteed by the judge that such a solution exists and is unique.
Hence in the first line of output, you must print 4 numbers: the number of different
routes with the least cost, the cost, the happiness, and the average happiness (take
the integer part only) of the recommended route. Then in the next line, you are
supposed to print the route in the format "City1->City2->...->ROM".
-------------------------------------------------------------------------------------
Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1

Sample Output:
3 3 195 97
HZH->PRS->ROM
===================================================================================*/

#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 210;
const int inf = 0x3fffffff;
map<int, string> int2str;
map<string, int> str2int;
int numP = 0, n, k, start;
int h[maxn], g[maxn][maxn], d[maxn];
bool vis[maxn];
char st[5];
vector<int> ans, temp;
vector<int> pre[maxn];

void Dijkstra(int st){
    fill(d, d + maxn, inf);
    fill(vis, vis + maxn, false);
    d[st] = 0;
    for (int i = 0; i < n; ++i){
        int u = -1, MIN = inf;
        for (int j = 0; j < n; ++j){
            if (vis[j] == false && d[j] < MIN){
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; ++v){
            if (vis[v] == false && g[u][v] != inf){
                if (d[v] > d[u] + g[u][v]){
                    d[v] = d[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[v] == d[u] + g[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int cnt = 0;
double maxH = 0, avgH = 0;
void DFS(int index, double totalH, int num){
    if (index == start){
        cnt++;
        if (totalH > maxH){
            maxH = totalH;
            avgH = totalH / num;
            ans = temp;
        }
        else if (totalH == maxH && totalH / num > avgH){
            avgH = totalH / num;
            ans = temp;
        }
        return;
    }
    for (int i = 0; i < pre[index].size(); ++i){
        int v = pre[index][i];
        temp.push_back(v);
        DFS(v, totalH + h[v], num + 1);
        temp.pop_back();
    }
}

int change(string s){
    if (str2int.find(s) == str2int.end()){
        str2int[s] = numP;
        int2str[numP] = s;
        return numP++;
    }
    else{
        return str2int[s];
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    fill(g[0], g[0] + maxn * maxn, inf);
    scanf("%d%d%s", &n, &k, st);
    start = change(st);
    h[start] = 0;
    for (int i = 0; i < n - 1; ++i){
        char s[5];
        int value, index;
        scanf("%s%d", s, &value);
        index = change(s);
        h[index] = value;
    }
    for (int i = 0; i < k; ++i){
        char s1[5], s2[5];
        int dis;
        scanf("%s%s%d", s1, s2, &dis);
        int u = change(s1);
        int v = change(s2);
        g[u][v] = g[v][u] = dis;
    }
    Dijkstra(start);
    int ed = str2int["ROM"];
    temp.push_back(ed);
    DFS(ed, h[ed], 0);
    printf("%d %d %d %d\n", cnt, d[ed], (int)maxH, (int)avgH);
    for (int i = ans.size() - 1; i >= 0; --i){
        cout << int2str[ans[i]];
        if (i != 0)
            printf("->");
    }
    printf("\n");
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}