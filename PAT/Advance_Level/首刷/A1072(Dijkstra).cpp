#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e3 + 20;
const int inf = 0x3fffffff;
int n, m, k, dmax;
int g[maxn][maxn], d[maxn];
double t[maxn];
bool vis[maxn];

int change(char s[]){
    int ans = 0;
    if (s[0] >= '0' && s[0] <= '9'){
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

void Dijkstra(int st){
    fill(d, d + maxn, inf);
    fill(vis, vis + maxn, false);
    d[st] = 0;
    for (int i = 0; i < n + m; ++i){
        int u = -1, MIN = inf;
        for (int i = 1; i <= n + m; ++i){
            if(vis[i] == false && d[i] < MIN){
                u = i;
                MIN = d[i];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for (int v = 1; v <= m + n; ++v){
            if(g[u][v] != inf && d[v] > d[u] + g[u][v]){
                d[v] = d[u] + g[u][v];
            }
        }
    }
}

double count(){
    double total = 0;
    for (int i = 1; i <= n; ++i){
        total += d[i];
    }
    return total;
}

int main() {
    freopen("data.txt", "r", stdin);
    fill(g[0], g[0] + maxn * maxn, inf);
    scanf("%d%d%d%d", &n, &m, &k, &dmax);
    for (int i = 0; i < k; ++i)
    {
        char s1[6], s2[6];
        int dis;
        scanf("%s%s%d", s1, s2, &dis);
        int u = change(s1);
        int v = change(s2);
        g[u][v] = g[v][u] = dis;
    }
    int index = -1;
    double MAX = 0;
    for (int i = n + 1; i <= n + m; ++i){
        Dijkstra(i);
        bool flag = true;
        double MIN = inf;
        t[i] = count();
        for (int j = 1; j <= n; ++j){
            if (d[j] > dmax){
                flag = false;
                break;
            }
            if (d[j] < MIN){
                MIN = d[j];
            }
        }
        if (flag){
            if (MAX < MIN){
                MAX = MIN;
                index = i;
            }
            else if (MAX == MIN){
                if (t[i] < t[index]){
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
        printf("G%d\n%.1lf %.1lf\n", index - n, MAX, t[index] / n);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}