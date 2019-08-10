#include<iostream>
#include<stack>
using namespace std;

void change(int n){
	stack<int> s;
	do{
		s.push(n % 13);
		n /= 13;
	}while(n > 0);
	while(s.size() < 2){
		s.push(0);
	}
	while(!s.empty()){
		int num = s.top();
		s.pop();
		if(num >= 10){
			printf("%c", 'A' + num - 10);
		}else{
			printf("%d", num);
		}
	}
}

int main(){
	printf("#");
	int n;
	for(int i = 0; i < 3; ++i){
		scanf("%d", &n);
		change(n);
	}
	return 0;
}
