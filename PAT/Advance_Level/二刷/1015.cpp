#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
	if(n <= 1)	return false;
	int M = sqrt(n);
	for(int i = 2; i <= M; ++i){
		if(n % i == 0)	return false;
	}
	return true;
}

int change(int n, int r){
	int ans = 0;
	while(n > 0){
		ans = ans * r + n % r;
		n /= r;
	}
	return ans;
}

int main(){
	freopen("data.txt", "r", stdin);
	int n, r;
	while(scanf("%d", &n), n > 0){
		scanf("%d", &r);
		int rn = change(n, r);
		if(isPrime(n) && isPrime(rn))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
