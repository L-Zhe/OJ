#include<iostream> 
#include<cmath>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	int data, next;
	bool flag;
}a[maxn];
int n, st;
bool h[maxn];

int main(){
	scanf("%d%d", &n, &st);
	for(int i = 0; i < n; ++i){
		int index;
		scanf("%d", &index);
		scanf("%d%d", &a[index].data, &a[index].next);
	}
	int cnt = 0, pre, temp = st;
	while(temp != -1){
		int key = abs(a[temp].data);
		if(h[key]){
			a[temp].flag = true;
			temp = a[temp].next;
			continue;
		}
		h[key] = true;
		++cnt;
		temp = a[temp].next;
	}
	printf("%d ", cnt);
	while(st != -1){
		if(a[st].flag){
			st = a[st].next;
			continue;
		}
		printf("%05d\n", st);
		printf("%05d %d ", st, a[st].data);
		st = a[st].next;
	}
	printf("-1\n");
	return 0;
}
