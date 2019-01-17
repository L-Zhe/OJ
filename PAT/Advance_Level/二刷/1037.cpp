#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int nc, np;
int c[maxn], p[maxn];

int main(){
	scanf("%d", &nc);
	int intc = 0, intp = 0, ans = 0;
	for(int i = 0; i < nc; ++i){
		scanf("%d", c + i);
		if(c[i] < 0)	++intc;
	}
	scanf("%d", &np);
	for(int i = 0; i < np; ++i){
		scanf("%d", p + i);
		if(p[i] < 0) 	++intp;
	}
	sort(c, c + nc);
	sort(p, p + np);
	for(int i = 0; i < intc && i < intp; ++i){
		ans += c[i] * p[i];
	}
	int i = nc - 1, j = np - 1;
	while(i >= intc && j >= intp){
		ans += c[i--] * p[j--];
	}
	printf("%d", ans);
	return 0;
}
