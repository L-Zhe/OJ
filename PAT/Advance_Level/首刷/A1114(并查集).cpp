#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10;
struct node{
    int num, area;
    bool flag;
    node(){
        num = 0;
        area = 0;
        flag = false;
    }
}mem[maxn];
struct family{
    int id, total;
    double total_num, total_area;
    double avg_num, avg_area;
    bool flag;
    family(){
        total = 0;
        total_num = 0;
        total_area = 0;
        flag = false;
    }
}ans[maxn];
int father[maxn];
int n, cnt = 0;

void init(){
    for(int i = 0; i < maxn; ++i){
        father[i] = i;
        ans[i].id = i;
    }
}

int findFather(int a){
    int x = a;
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
    if(fa != fb)
        father[max(fa, fb)] = min(fa, fb);
}

bool cmp(family a, family b){
    if(a.flag != b.flag)
        return a.flag > b.flag;
    else if(a.avg_area != b.avg_area)
        return a.avg_area > b.avg_area;
    return a.id < b.id;
}

int main(){
    freopen("data.txt", "r", stdin);
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int id, f, m, k;
        scanf("%d%d%d%d", &id, &f, &m, &k);
        mem[id].flag = true;
        if(f != -1){
            Union(f, id);
            mem[f].flag = true;
        }
        if(m != -1){
            Union(m, id);
            mem[m].flag = true;
        }
        for(int j = 0; j < k; ++j){
            int child;
            scanf("%d", &child);
            mem[child].flag = true;
            Union(id, child);
        }
        scanf("%d%d", &mem[id].num, &mem[id].area);
    }
    for(int i = 0; i < maxn; ++i){
        if(mem[i].flag){
            int index = findFather(i);
            if(!ans[index].flag){
                ++cnt;
                ans[index].flag = true;
            }
            ++ans[index].total;
            ans[index].total_num += mem[i].num;
            ans[index].total_area += mem[i].area;
            ans[index].avg_num = ans[index].total_num / ans[index].total;
            ans[index].avg_area = ans[index].total_area / ans[index].total;
        }
    }
    printf("%d\n", cnt);
    sort(ans, ans + maxn, cmp);
    for(int i = 0; i < cnt; ++i){
        printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].total, ans[i].avg_num, ans[i].avg_area);
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}