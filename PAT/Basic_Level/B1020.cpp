#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1010;
struct node{
	double store;
	double price;
	double total;
}p[maxn];
int n;
double m;

bool cmp(node a, node b){
	return a.price > b.price;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%lf", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%lf", &p[i].store);
	}
	for(int i = 0; i < n; ++i){
		scanf("%lf", &p[i].total);
		p[i].price = p[i].total / p[i].store;
	}
	sort(p, p + n, cmp);
	double total = 0;
	for(int i = 0; i < n; ++i){
		if(p[i].store < m){
			total += p[i].total;
			m -= p[i].store;
		}
		else{
			total += m * p[i].price;
			break;
		}
	}
	printf("%.2f", total);
	return 0;
}
