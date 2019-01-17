#include<iostream>
#include<vector>
using namespace std;

const int maxn = 50;
int n, cnt = 0;
int Hash[maxn];


int calSum(int n){
	int ans = 0;
	while(n > 0){
		ans += n % 10;
		n /= 10;
	}
	return ans;
} 

int main(){
	fill(Hash, Hash + maxn, 0);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int temp, sum;
		scanf("%d", &temp);
		sum = calSum(temp);
		if(!Hash[sum]){
			++cnt;
		}
		++Hash[sum];
	}
	printf("%d\n", cnt);
	bool flag = false;
	for(int i = 0; i < maxn; ++i){
		if(Hash[i]){
			if(flag)
				printf(" ");
			flag = true;
			printf("%d", i);
		}
	}
	return 0;
}
