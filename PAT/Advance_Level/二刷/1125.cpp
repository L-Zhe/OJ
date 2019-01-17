#include<iostream>
#include<queue>
using namespace std;

int n;
priority_queue<double, vector<double>, greater<double> > q;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		double temp;
		scanf("%lf", &temp);
		q.push(temp);
	}
	while(q.size() > 1){
		double u = q.top();
		q.pop();
		double v = q.top();
		q.pop();
		q.push((u + v) / 2);
	}
	printf("%d", (int)q.top());
	return 0;
}
