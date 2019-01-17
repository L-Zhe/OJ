#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int power(int a, int n){
	int ans = 1;
	while(n > 0){
		if(n & 1){
			ans *= a;
		}
		a *= a;
		n >>= 1;
	}
	return ans;
}

int power2(int a, int n){
	if(n == 0)
		return 1;
	if(n & 1){
		return a*power2(a, n-1);
	}
	else{
		int temp = power2(a, n / 2);
		return temp * temp;
	}
}

int main(){
	int a, n;
	cin >> a >> n;
	cout << power(a, n) << endl << power2(a, n);
	return 0;
}