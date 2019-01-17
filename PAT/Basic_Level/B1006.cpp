#include<iostream>
#include<stack>
using namespace std;

char c[2] = {'S', 'B'};

int main(){
	int n;
	cin >> n;
	stack<int> s;
	while(n > 0){
		s.push(n % 10);
		n /= 10;
	}
	int temp;
	while(s.size() > 1){
		temp = s.top();
		s.pop();
		for(int i = 0; i < temp; ++i)
			cout << c[s.size() - 1];
	}
	temp = s.top();
	for(int i = 1; i <= temp; ++i)
		cout << i;
	return 0;
}