#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const long maxn = 1e5 + 10;
struct node{
	long fac, cnt;
};
vector<node> ans;
long prime[maxn];
bool p[maxn];
long n;
int len = 0;
void euler(){
	p[0] = p[1] = true;
	for(long i = 2; i < maxn; ++i){
		if(!p[i])	prime[len++] = i;
		for(long j = 1; j < len && i * prime[j] < maxn; ++j){
			p[i * prime[j]] = true;
			if(!i % prime[j])	break;
		}
	}
}

int main(){
	scanf("%ld", &n);
	if(n == 1){
		printf("1=1");
		return 0;
	}
	printf("%ld=", n);
	euler();
	len = 0;
	long MAX = sqrt(n);
	while(n > 1 && prime[len] < MAX){
		if(n % prime[len] == 0){
			node temp;
			temp.fac = prime[len];
			int cnt = 0;
			while(n % prime[len] == 0){
				n /= prime[len];
				++cnt;
			}
			temp.cnt = cnt;
			ans.push_back(temp);
		}
		++len;
	}
	if(n != 1){
		node temp;
		temp.cnt = 1;
		temp.fac = n;
		ans.push_back(temp);
	}
	for(int i = 0; i < ans.size(); ++i){
		if(i != 0)	printf("*");
		printf("%ld", ans[i].fac);
		if(ans[i].cnt != 1)
			printf("^%d", ans[i].cnt);
	}
	return 0;
}
