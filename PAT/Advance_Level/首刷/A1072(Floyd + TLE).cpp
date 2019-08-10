/*===================================================================================
A1072 Gas Station (30)£¨30 ·Ö£©
=====================================================================================
A gas station has to be built at such a location that the minimum distance between
the station and any of the residential housing is as far away as possible. However
it must guarantee that all the houses are in its service range.
Now given the map of the city and several candidate locations for the gas station,
you are supposed to give the best recommendation. If there are more than one solution,
output the one with the smallest average distance to all the houses. If such a solution
is still not unique, output the one with the smallest index number.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains 4
positive integers: N (<= 10^3^), the total number of houses; M (<= 10), the total
number of the candidate locations for the gas stations; K (<= 10^4^), the number
of roads connecting the houses and the gas stations; and D~S~, the maximum service
range of the gas station. It is hence assumed that all the houses are numbered from
1 to N, and all the candidate locations are numbered from G1 to GM.
Then K lines follow, each describes a road in the format\ P1 P2 Dist\ where P1 and
P2 are the two ends of a road which can be either house numbers or gas station numbers,
and Dist is the integer length of the road.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in the first line the index number of the best location.
In the next line, print the minimum and the average distances between the solution
and all the houses. The numbers in a line must be separated by a space and be accurate
up to 1 decimal place. If the solution does not exist, simply output ¡°No Solution¡±.
-------------------------------------------------------------------------------------
Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2

Sample Output 1:
G1
2.0 3.3
------------------
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20

Sample Output 2:
No Solution
===================================================================================*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1e3 + 20;
const int inf = 0x3fffffff;
int n, m, k, dmax;
int g[maxn][maxn];
bool vis[maxn];

int change(char s[]){
    int ans = 0;
    if(s[0] >= '0' && s[0] <= '9'){
        for (int i = 0; i < strlen(s); ++i)
            ans = ans * 10 + s[i] - '0';
    }
    else{
        for (int i = 1; i < strlen(s); ++i){
            ans = ans * 10 + s[i] - '0';
        }
        ans += n;
    }
    return ans;
}

void floyd(){
    for (int k = 1; k <= n + m; ++k){
        for (int i = 1; i <= n + m; ++i){
            for (int j = 1; j <= n + m; ++j){
                if(g[i][k] != inf && g[k][j] != inf && g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
}

double count(int index){
    double total = 0;
    for (int i = 1; i <= n; ++i){
        total += g[index][i];
    }
    return total;
}

int main(){
    freopen("data.txt", "r", stdin);
    fill(g[0], g[0] + maxn * maxn, inf);
    scanf("%d%d%d%d", &n, &m, &k, &dmax);
    for (int i = 0; i < k; ++i){
        char s1[6], s2[6];
        int dis;
        scanf("%s%s%d", s1, s2, &dis);
        int u = change(s1);
        int v = change(s2);
        g[u][v] = g[v][u] = dis;
    }
    floyd();
    int  index = -1;
    double MAX = 0;
    for (int i = n + 1; i <= n + m; ++i){
        bool flag = true;
        double MIN = inf;
        for (int j = 1; j <= n; ++j){
            if(g[i][j] > dmax){
                flag = false;
                break;
            }
            if(g[i][j] < MIN){
                MIN = g[i][j];
            }
        }
        if(flag){
            if(MAX < MIN){
                MAX = MIN;
                index = i;
            }
            else if(MAX == MIN){
                if(count(i) < count(index)){
                    index = i;
                }
                else{
                    index = min(i, index);
                }
            }
        }
    }
    if (index == -1){
        printf("No Solution\n");
    }
    else{
        printf("G%d\n%.1lf %.1lf\n", index - n, MAX, count(index) / n);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}