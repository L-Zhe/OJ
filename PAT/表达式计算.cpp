#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<map>
using namespace std;

struct node{
	double num;
	char op;
	bool flag;
};
string st;
queue<node> q;
stack<node> s;
map<char, int> op;

void change(){
	double num;
	node temp;
	for(int i = 0; i < st.length();){
		temp.flag = true;
		if(st[i] >= '0' && st[i] <= '9'){
			temp.num = st[i++] - '0';
		while(i < st.length() && st[i] >= '0' && st[i] <= '9'){
			temp.num = temp.num * 10 + (st[i] - '0');
			++i;
		}	
		q.push(temp);	
		}
		else{
			temp.flag  = false;
			if(st[i] == '('){
				temp.op = st[i];
				s.push(temp);
			}else if(st[i] == ')'){
				while(s.top().op != '('){
					q.push(s.top());
					s.pop();
				}
				s.pop();
			}else{
				while(!s.empty() && op[st[i]] <= op[s.top().op]){
					q.push(s.top());
					s.pop();
				}
				temp.op = st[i];
				s.push(temp);
			}
			++i;
		}
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

double cal(){
	double temp1, temp2;
	node cur, temp;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.flag == true)	s.push(cur);
		else{
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			temp.flag = true;
			if(cur.op == '+')	temp.num = temp1 + temp2;
			if(cur.op == '-')	temp.num = temp1 - temp2;
			if(cur.op == '*')	temp.num = temp1 * temp2;
			if(cur.op == '/')	temp.num = temp1 / temp2;
			s.push(temp);
		}
	}
	return s.top().num;
}

int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	getline(cin, st);
	for(string::iterator it = st.end(); it != st.begin(); it--)
		if(*it == ' ')	st.erase(it);
	while(!s.empty())	s.pop();
	change();
	printf("%.2f", cal());
	return 0;
}
