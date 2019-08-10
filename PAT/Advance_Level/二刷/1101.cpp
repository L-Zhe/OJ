#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 1e9 + 10;
int a[maxn], c[maxn];
int n;
bool Left[maxn], Right[maxn];

int main(){
	scanf("%d", &n);
	int MAX = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
		if(a[i] > MAX){
			Left[i] = true;
			MAX = a[i];
		}
	}
	int MIN = inf;
	for(int i = n - 1; i >= 0; --i){
		if(a[i] < MIN){
			MIN = a[i];
			Right[i] = true;
		}
	}
	int len = 0;
	for(int i = 0; i < n; ++i){
		if(Left[i] && Right[i]){
			c[len++] = a[i];
		}
	}
	printf("%d\n", len);
	for(int i = 0; i < len; ++i){
		if(i != 0)	printf(" ");
		printf("%d", c[i]);
	}
	printf("\n");
	return 0;
}
