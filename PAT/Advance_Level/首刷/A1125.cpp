#include<iostream>
#include<queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		q.push(temp);
	}
	while(q.size() > 1){
		int a1 = q.top();
		q.pop();
		int a2 = q.top();
		q.pop();
		int a = (a1 + a2) / 2;
		q.push(a);
	}
	printf("%d", q.top());
	return 0;
}

