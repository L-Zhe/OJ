//算法笔记上做法MLE
#include<iostream>
using namespace std;

const int inf = 0x7fffffff;
const int maxn= 200001;
int n1, n2;
int a[maxn];

int main(){
	freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n1;
	for(int i = 0; i < n1; ++i){
		cin >> a[i];
	}
	cin >> n2;
	int mid = (n1 + n2 + 1)/2;
	int midNum, index = 0;
	for(int i = 0; i < n2; ++i){
		int temp;
		cin >> temp;
		while(index < n1 && temp > a[index]){
			mid--;
			if(mid == 0)
				midNum = a[index];
			index++;
		}
		mid--;
		if(mid == 0)
			midNum = temp;
		//cout << mid << endl;
	}
	while(mid > 0){
		mid--;
		if(mid == 0)
			midNum = a[index];
		index++;
	}
	cout << midNum;
	return 0;
}