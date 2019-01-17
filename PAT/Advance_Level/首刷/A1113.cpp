#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
int n, sum;

int partition(int left, int right){
    int p = round(1.0 * rand() / RAND_MAX * (right - left) + left);
    swap(a[p], a[left]);
    int i = left;
    for(int j = i + 1; j <= right; ++j){
        if(a[j] < a[left]){
            swap(a[j], a[++i]);
        }
    }
    swap(a[i], a[left]);
    return i;
}

void rand_Selection(int left, int right, int k){
    if(left == right)   return;
    int p = partition(left, right);
    int m = p - left + 1;
    if(m == k)  return;
    if(m > k)
        rand_Selection(left, p - 1, k);
    else
        rand_Selection(p + 1, right, k - m);
}

int main(){
    srand((unsigned)time(NULL));
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", a + i);
        sum += a[i];
    }
    rand_Selection(0, n - 1, n / 2);
    int s2 = 0;
    for(int i = 0; i < n / 2; ++i)
        s2 += a[i];
    printf("%d %d\n", (n - n / 2) - n / 2, (sum - s2) - s2);
    system("pause");
    return 0;
}