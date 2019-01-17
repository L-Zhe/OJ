#include<iostream>
using namespace std;

const int maxn = 1e5 + 10;
int d[maxn], m[maxn];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int dis;
        scanf("%d", &dis);
        ++d[dis];
    }
    for(int i = maxn - 2; i >= 0; --i){
        m[i] = d[i + 1] + m[i + 1];
    }
    for(int i = maxn - 1; i >= 0; --i){
        if(m[i] >= i){
           printf("%d\n", i); 
           break;
        }
    }

    system("pause");
    return 0;
}
