#include<iostream>
using namespace std;

const int maxn = 110;
int a[maxn], n, m;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	bool flag = false;
	while(m > n){
		m -= n;
	}
	for(int i = n - m; i < n; ++i){
		if(flag)
			cout << " ";
		flag = true;
		cout << a[i];
	}
	for(int i = 0; i < n - m; ++i){
		if(flag)
			cout << " ";
		flag = true;
		cout << a[i];
	}
	return 0;
}