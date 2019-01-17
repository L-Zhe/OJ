/*===================================================================================
A1146 Topological Order（25 分）
=====================================================================================
This is a problem given in the Graduate Entrance Exam in 2018: Which of the following
is NOT a topological order obtained from the given directed graph? Now you are supposed
to write a program to test each of the options.
===================================================================================*/

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e3 + 10;
int inDegree[maxn], g[maxn][maxn], temp[maxn];
int n, m, k;
vector<int> ans;

int main()
{
    freopen("data.txt", "r", stdin);
    fill(g[0], g[0] + maxn * maxn, 0);
    fill(inDegree, inDegree + maxn, 0);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = 1;
        inDegree[v]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < maxn; ++j)
        {
            temp[j] = inDegree[j];
        }
        bool flag = true;
        for (int j = 0; j < n; ++j)
        {
            int u;
            scanf("%d", &u);
            if (temp[u] != 0 && flag)
            {
                ans.push_back(i);
                flag = false;
            }
            for (int v = 1; v <= n; ++v)
            {
                if (g[u][v] == 1)
                    temp[v]--;
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}