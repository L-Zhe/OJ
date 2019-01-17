#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1e5 + 10;
typedef long long ll;
struct node{
	int id;
	char name[9];
	int grade;
}a[maxn];
int n, c;

bool cmp1(node a, node b){
	return a.id < b.id;
}

bool cmp2(node a, node b){
	if(strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
	else
		return a.id < b.id;
}

bool cmp3(node a, node b){
	if(a.grade != b.grade)
		return a.grade < b.grade;
	else 
		return a.id < b.id;
}

int main(){
	scanf("%d%d", &n, &c);
	for(int i = 0; i < n; ++i){
		scanf("%d%s%d", &a[i].id, a[i].name, &a[i].grade);
	}
	if(c == 1)	sort(a, a + n, cmp1);
	else if(c == 2)	sort(a, a + n, cmp2);
	else	sort(a, a + n, cmp3);
	for(int i = 0; i < n; ++i){
		printf("%06d %s %d\n", a[i].id, a[i].name, a[i].grade);
	}
	return 0;
}
