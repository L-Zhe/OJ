#include<iostream>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	char s;
	int next;
	bool flag;
	node(){
		flag = false;
	}
}a[maxn];
int n, st1, st2;

int main(){
	scanf("%d%d%d", &st1, &st2, &n);
	for(int i = 0; i < n; ++i){
		int ad, next;
		char s;
		scanf("%d %c %d", &ad, &s, &next);
		a[ad].next = next;
		a[ad].s = s;
	}
	while(st1 != -1){
		a[st1].flag = true;
		st1 = a[st1].next;
	}
	while(st2 != -1){
		if(a[st2].flag)	break;
		st2 = a[st2].next;
	}
	if(st2 != -1)
		printf("%05d", st2);
	else
		printf("-1");
	return 0;
}
