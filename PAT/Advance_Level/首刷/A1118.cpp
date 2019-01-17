#include<iostream>
using namespace std;

const int maxn = 1e4 + 10;
int father[maxn];
bool isFather[maxn], isCount[maxn];
int n, q, cnt_tree = 0, cnt_bird = 0;

void init(){
    for(int i = 0; i < maxn; ++i)
        father[i] = i;
}

int findFather(int a){
    int x = a;
    while(x != father[x]){
        x  = father[x];
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
        father[fa] = fb;
}

int main(){
    freopen("data.txt", "r", stdin);
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int num, pre;
        scanf("%d", &num);
        for(int j = 0; j < num; ++j){
            int bird;
            scanf("%d", &bird);
            if(!isCount[bird]){
                ++cnt_bird;
                isCount[bird] = true;
            }
            if(j > 0){
                Union(pre, bird);
            }
            pre = bird;
        }
    }
    for(int i = 0; i < maxn; ++i){
        if(isCount[i] && father[i] == i){
            ++cnt_tree;
        }
    }
    printf("%d %d\n", cnt_tree, cnt_bird);
    scanf("%d", &q);
    for(int i = 0; i < q; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        if(findFather(a) == findFather(b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}
