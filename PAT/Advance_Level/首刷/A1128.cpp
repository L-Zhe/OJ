#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1010;
bool Hash[maxn];
int k, n;
int column[maxn];

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d", &n);
		fill(Hash, Hash + n + 1, false);
		bool flag = true;
		for(int j = 1; j <= n; ++j){
			int temp;
			scanf("%d", &temp);
			column[j] = temp;
			if(Hash[temp]){
				flag = false;
			}
			Hash[temp] = true;
			for(int u = 1; u < j; ++u){
				if(abs(u - j) == abs(column[u] - column[j]))
					flag = false;
			}
		}
		if(flag)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
