#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

void print(ll n){
	stack<char> s;
	if(n < 0){
		printf("-");
		n *= -1;
	}
	int cnt = 0;
	do{
		s.push(n % 10 + '0');
		n /= 10;
		if(++cnt == 3){
			cnt = 0;
			s.push(',');	
		}
	}while(n != 0);
	if(s.top() == ',')	s.pop();
	while(!s.empty()){
		printf("%c", s.top());
		s.pop();
	}
}

int main(){
	ll a, b;
	scanf("%lld%lld", &a, &b);
	a = a + b;
	print(a);
	return 0;
} 
