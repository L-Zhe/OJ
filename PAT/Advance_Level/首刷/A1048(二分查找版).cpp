#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int a[maxn];
int n, m;

int binarySearch(int i, int j, int x){
    int left = i, right = j, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    bool flag = false;
    for (int i = 1; i <= n; ++i){
        int j = binarySearch(i + 1, n, m - a[i]);
        if(j != -1){
            printf("%d %d", a[i], a[j]);
            flag = true;
            break;
        }
    }
    if(!flag)
        printf("No Solution");
    system("pause");
    return 0;
}