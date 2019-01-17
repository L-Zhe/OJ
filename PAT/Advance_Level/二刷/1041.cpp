#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1e4 + 10;
int n;
int h[maxn];
vector<int> a;

int main(){
	scanf("%d", &n);
	int num;
	for(int i = 0; i < n; ++i){
		scanf("%d", &num);
		++h[num];
		a.push_back(num);
	}
	int i;
	for(i = 0; i < a.size(); ++i){
		if(h[a[i]] == 1){
			printf("%d", a[i]);
			break;
		}
	}
	if(i == a.size())
		printf("None");
	return 0;
}
