#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isPrime(int n){
	if(n < 2)	return false;
	int MAX = sqrt(n);
	for(int i = 2; i <= MAX; ++i)
		if(n % i == 0)	return false;
	return true;
}

int main(){
	int msize, m, n;
	scanf("%d%d%d", &msize, &n, &m);
	while(!isPrime(msize))	++msize;
	vector<int> ans(msize);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		int k = 0;
		while(k < msize && ans[(temp + k * k) % msize] != 0) ++k;
		if(k == msize)	printf("%d cannot be inserted.\n", temp);
		else	ans[(temp + k * k) % msize] = temp;
	}
	int cnt = 0;
	for(int i = 0; i < m; ++i){
		int temp, k = 0;
		scanf("%d", &temp);
		while(k < msize && ans[(temp + k * k) % msize] != temp && ans[(temp + k * k) % msize] != 0) ++k;
		cnt += k + 1;
	}
	printf("%.1f", 1.0 * cnt / m);
	return 0;
}
