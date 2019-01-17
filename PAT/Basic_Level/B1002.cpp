#include<iostream>
#include<string>
#include<stack>
using namespace std;

string s;

void output(int i){
	if(i == 1)	cout << "yi";
	if(i == 2)	cout << "er";
	if(i == 3)	cout << "san";
	if(i == 4)	cout << "si";
	if(i == 5)	cout << "wu";
	if(i == 6)	cout << "liu";
	if(i == 7)	cout << "qi";
	if(i == 8)	cout << "ba";
	if(i == 9)	cout << "jiu";
	if(i == 0)	cout << "ling";
}

int main(){
	cin >> s;
	int total = 0;
	for(int i = 0; i < s.length(); ++i)
		total += s[i] - '0';
	stack<int> p;
	while(total > 0){
		int temp = total % 10;
		p.push(temp);
		total /= 10;
	}
	bool flag = false;
	int len = p.size();
	for(int i = 0; i < len; ++i){
		if(flag)
			cout << " ";
		flag = true;
		output(p.top());
		p.pop();
	}
	return 0;
}