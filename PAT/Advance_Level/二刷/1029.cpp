#include<iostream>
using namespace std;

const int maxn = 2e5 + 10;
const int inf = 0x7fffffff;
int a[maxn];
bool flag = false;
int main(){
	freopen("data.txt", "r", stdin);
	int n1, n2, mid;
	scanf("%d", &n1);
	for(int i = 0; i < n1; ++i){
		scanf("%d", a + i);
	}
	a[n1] = inf;
	scanf("%d", &n2);
	mid = (n1 + n2 + 1) / 2;
	int temp, index = 0;
	for(int i = 0; i < n2; ++i){
		scanf("%d", &temp);
		while(temp > a[index]){
			--mid;
			if(mid == 0){
				printf("%d", a[index]);
				flag = true;
				break;
			}
			++index;
		}
		if(flag){
			break;
		}else{
			--mid;
			if(mid == 0){
				printf("%d", temp);
				break;
			}
		}
	}
	if(mid != 0)	printf("%d", a[index + mid - 1]);
	return 0;
}
