#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
using namespace std;

struct node{
	bool flag;
	double num;
	char op;	
};
map<char, int> mp;

queue<node> change(char* s){
	queue<node> ans;
	stack<node> op;
	int i = 0;
	while(i < strlen(s)){
		node temp;
		double num = 0;
		if(s[i] >= '0' && s[i] <= '9'){
			temp.flag = true;
			while(i < strlen(s) && s[i] >= '0' && s[i] <= '9'){
				num = num * 10 + s[i] - '0';
				++i;
			}
			temp.num = num;
			ans.push(temp);
		}else{
			temp.flag = false;
			if(s[i] == '('){
				temp.op = s[i];
				op.push(temp);
			}else if(s[i] == ')'){
				while(op.top().op != '('){
					ans.push(op.top());
					op.pop();
				}
				op.pop();
			}else{
				while(!op.empty() && mp[s[i]] <= mp[op.top().op]){
					ans.push(op.top());
					op.pop();
				}
				temp.op = s[i];
				op.push(temp);
			}
			++i;
		}
	}
	while(!op.empty()){
		ans.push(op.top());
		op.pop();
	}
	return ans;
}

double cal(queue<node> ans){
	stack<node> s;
	double num1, num2;
	node cur, temp;
	while(!ans.empty()){
		cur = ans.front();
		ans.pop();
		if(cur.flag)	s.push(cur);
		else{
			num2 = s.top().num;
			s.pop();
			num1 = s.top().num;
			s.pop();
			temp.flag = true;
			if(cur.op == '+')	temp.num = num1 + num2;
			if(cur.op == '-')	temp.num = num1 - num2;
			if(cur.op == '*')	temp.num = num1 * num2;
			if(cur.op == '/')	temp.num = num1 / num2;
			s.push(temp);
		}
	}
	return s.top().num;
}

int main(){
	mp['+'] = mp['-'] = 1;
	mp['*'] = mp['/'] = 2;
	char s[210];
	scanf("%s", s);
	queue<node> ans = change(s);
	printf("%.2f", cal(ans));
	return 0;
}
