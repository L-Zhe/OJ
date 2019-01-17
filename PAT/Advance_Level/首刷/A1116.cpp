#include<iostream>
using namespace std;

const int maxn = 1e4 + 10;
int id[maxn];
bool p[maxn], isRank[maxn], isCheck[maxn];

void findPrime(){
    p[0] = true;
    p[1] = true;
    for(int i = 2; i < maxn; ++i){
        if(p[i] == false){
            for(int j = i + i; j < maxn; j += i)
                p[j] = true;
        }
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    findPrime();
    int n, k;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int ID;
        scanf("%d", &ID);
        id[ID] = i;
        isRank[ID] = true;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; ++i){
        int query;
        scanf("%d", &query);
        printf("%04d: ", query);
        if(isRank[query]){
            if(isCheck[query]){
                printf("Checked\n");
            }else{
                int rank = id[query];
                isCheck[query] = true;
                if(rank == 1)
                    printf("Mystery Award\n");
                else if(!p[rank])
                    printf("Minion\n");
                else
                    printf("Chocolate\n");
            }
        }else{
            printf("Are you kidding?\n");
        }
    }
    freopen("Con", "r", stdin);
    system("pause");
    return 0;
}