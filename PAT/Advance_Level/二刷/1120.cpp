#include<iostream>
using namespace std;

const int maxn = 50;
int h[maxn];
int n;

int cal(int n){
	int ans = 0;
	while(n > 0){
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		int index = cal(temp);
		if(h[index] == 0)	++cnt;
		++h[index];
	}
	printf("%d\n", cnt);
	bool flag = false;
	for(int i = 0; i < maxn; ++i){
		if(h[i]){
			if(flag)	printf(" ");
			flag = true;
			printf("%d", i);
		}
	}
	return 0;
}
