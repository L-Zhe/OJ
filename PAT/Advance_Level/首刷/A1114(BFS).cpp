#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10;
struct node{
    int num, area;
    node(){
        area = 0;
        num = 0;
    }
}mem[maxn];
struct item{
    int id, total;
    double avgnum, avga;
};
vector<item> ans;
vector<int> g[maxn];
int n;
int total;
double ta, tn;
bool vis[maxn], flag[maxn];

bool cmp(item a, item b){
    if(a.avga != b.avga)
        return a.avga > b.avga;
    return a.id < b.id;
}

int BFS(int root){
    total = 0; tn = 0; ta = 0;
    int mini = maxn;
    queue<int> q;
    q.push(root);
    vis[root] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(top < mini)
            mini = top;
        total++;
        tn += mem[top].num;
        ta += mem[top].area;
        for(int i = 0; i < g[top].size(); ++i){
            int v = g[top][i];
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return mini;
}

int main(){
    freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int id, fa, ma, k;
        scanf("%d%d%d%d", &id, &fa, &ma, &k);
        flag[id] = true;
        if(fa != -1){
            g[id].push_back(fa);
            g[fa].push_back(id);
            flag[fa] = true;    
        }
        if(ma != -1){
            g[id].push_back(ma);
            g[ma].push_back(id);
            flag[fa] = true;
        }
        for(int j = 0; j < k; ++j){
            int child;
            scanf("%d", &child);
            flag[child] = true;
            g[id].push_back(child);
            g[child].push_back(id);
        }
        scanf("%d%d", &mem[id].num, &mem[id].area);
    }
    for(int i = 0; i < maxn; ++i){
        if(!vis[i] && flag[i]){
            item temp;
            temp.id = BFS(i);
            temp.total = total;
            temp.avgnum = tn / total;
            temp.avga = ta / total;
            ans.push_back(temp);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i){
        printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].total, ans[i].avgnum, ans[i].avga);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}
