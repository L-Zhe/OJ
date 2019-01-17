#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], n;

int main(){
	scanf("%d", &n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
		sum += a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n / 2; ++i){
		ans += a[i];
	}
	printf("%d %d", n % 2, sum - 2 * ans);
	return 0;
}
