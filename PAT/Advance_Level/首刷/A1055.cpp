#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	char name[10];
	int age, w;
}a[maxn];
int n, k;

bool cmp(node a, node b){
	if(a.w != b.w)
		return a.w > b.w;
	else if(a.age != b.age)
		return a.age < b.age;
	return strcmp(a.name, b.name) < 0;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%s%d%d", a[i].name, &a[i].age, &a[i].w);
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < k; ++i){
		int l, r, m;
		scanf("%d%d%d", &m, &l, &r);
		bool flag = true;
		int j = 0;
		printf("Case #%d:\n", i + 1);
		while(m > 0 && j < n){
			if(a[j].age >= l && a[j].age <= r){
				printf("%s %d %d\n", a[j].name, a[j].age, a[j].w);
				flag = false;
				--m;
			}
			++j;
		}
		if(flag)
			printf("None\n");
	}
	return 0;
}