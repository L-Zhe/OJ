#include<iostream>
using namespace std;

const int maxn = 1ll << 25;
int h[maxn];
int MAX = 0, m, n;

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			int temp;
			scanf("%d", &temp);
			++h[temp];
			if(h[temp] > h[MAX]){
				MAX = temp;
			}
		}
	}
	printf("%d", MAX);
	return 0;
}
