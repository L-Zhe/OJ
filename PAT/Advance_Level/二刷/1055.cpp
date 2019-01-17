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
	else
		return strcmp(a.name, b.name) < 0;
}

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%s %d %d", a[i].name, &a[i].age, &a[i].w);
	}
	sort(a, a + n, cmp);
	int m, low, high;
	for(int i = 0; i < k; ++i){
		scanf("%d%d%d", &m, &low, &high);
		int cnt = 0;
		printf("Case #%d:\n", i + 1);
		for(int j = 0; j < n; ++j){
			if(a[j].age >= low && a[j].age <= high){
				printf("%s %d %d\n", a[j].name, a[j].age, a[j].w);
				if(++cnt == m)	break;
			}
		}
		if(cnt == 0)	printf("None\n");
	}
	return 0;
}


