#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

bool cmp(int a, int b){
	return a < b;
}

int main(){
	scanf("%d%d", &n, &m);
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end(), cmp);
	int i = 0, j = n - 1;
	while(i < j){
		while(a[i] + a[j] > m && i < j)	--j;
		while(a[i] + a[j] < m && i < j)	++i;
		if(a[i] + a[j] == m){
			break;
		}	
	}
	if(i != j)
		printf("%d %d", a[i], a[j]);
	else
		printf("No Solution");
	return 0;
}


