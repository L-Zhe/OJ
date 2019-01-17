#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1e5;
int a[maxn];
bool h[maxn];

bool isPrime(int n){
	if(n < 2)	return false;
	int MAX = sqrt(n);
	for(int i = 2; i <= MAX; ++i){
		if(n % i == 0)	return false;
	}
	return true;
}

int main(){
	int n, num;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &num);
		a[num] = i;
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		scanf("%d", &num);
		printf("%04d: ", num);
		if(h[num] && a[num] != 0){
			printf("Checked\n");
		}else{
			if(a[num] == 1){
				printf("Mystery Award\n");
			}else if(isPrime(a[num])){
				printf("Minion\n");
			}else if(a[num] != 0){
				printf("Chocolate\n");
			}else{
				printf("Are you kidding?\n");
			}
			h[num] = true;	
		}	
	}
	return 0;
}
