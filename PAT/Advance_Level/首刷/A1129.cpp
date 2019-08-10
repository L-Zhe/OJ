#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 5e4 + 10;
int a[maxn], cnt[maxn];
int n, k;

bool cmp(int a, int b){
	if(cnt[a] != cnt[b])
		return cnt[a] > cnt[b];
	return a < b;
}

int main(){
	scanf("%d%d", &n, &k);
	scanf("%d", a);
	++cnt[a[0]];
	int len = 1;
	for(int i = 1; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		printf("%d:", temp);
		for(int j = 0; j < len && j < k; ++j){
			printf(" %d", a[j]);
		}
		printf("\n");
		int index;
		if(cnt[temp] == 0){
			a[len] = temp;
			index = len++;
		}else{
			for(index = 0; index < len; ++index)
				if(a[index] == temp)
					break;
		}
		++cnt[temp];
		if(len > k){
			swap(a[index], a[k]);
		}
		sort(a, a + min(len, k + 1), cmp);
	}
	return 0;
}
