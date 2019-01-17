#include<cmath>
#include<cstdio>

bool idPrime(int n){
	if(n <= 1)	return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 0; i <= sqr; ++i){
		if(n % i == 0)	return false;
	}
	return true;
}

const int maxn = 10001;
int prime[maxn], pNum = 0;
bool p[maxn] = { false };
void findPrime(){
	for(int i = 2; i < maxn; ++i){
		if(p[i] == false)
			prime[pNum++] = i;
		for(int j = i + i; j < maxn; j += i){
			p[j] = true;
		}
	}
}

int main(){
	findPrime();
	for(int i = 0; i < pNum; ++i)
		printf("%d ", prime[i]);
	return 0;
}
