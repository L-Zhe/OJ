#include<iostream>
using namespace std;

const int inf = 0x7fffffff;
const int maxn= 200001;
int n1, n2;
int a1[maxn], a2[maxn];

int main(){
	freopen("data.txt", "r", stdin);
	//ios::sync_with_stdio(false);
	cin >> n1;
	for(int i = 0; i < n1; ++i){
		scanf("%d", a1 + i);
	}
	a1[n1] = inf;
	cin >> n2;
	for(int i = 0; i < n2; ++i){
		scanf("%d", a2 + i);
	}
	a2[n2] = inf;
	int mid = (n1 + n2 + 1)/2;
	int cnt = 0;
	int index1 = 0, index2 = 0;
	int midNum;
	while(cnt != mid){
		if(a1[index1] < a2[index2])
			midNum = a1[index1++];
		else
			midNum = a2[index2++];
		cnt++;
	}
	cout << midNum;
	return 0;
}