#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 1e3 + 10;
int a[maxn];
int n;
bool h[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int k;
		scanf("%d", &k);
		memset(h, 0, sizeof(h));
		bool flag = true;
		for(int j = 0; j < k; ++j){
			scanf("%d", a + j);
			if(h[a[j]])	flag = false;
			h[a[j]] = true;
			for(int index = 0; index < j; ++index){
				if(abs(index - j) == abs(a[index] - a[j]))
					flag = false;
			}
		}
		if(flag)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
